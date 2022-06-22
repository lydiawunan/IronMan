import pandas as pd
import numpy as np
from numpy.random import seed

import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
from tensorflow.keras import initializers
from tensorflow.keras.models import load_model


from tensorflow.keras import Model
from tensorflow.keras.optimizers import Adam, SGD
import matplotlib.pyplot as plt


import pickle

from tensorflow.python.framework import ops

from hls_env import hls_env

import argparse
import pprint as pp

def main(args):

    # Configuration parameters for the whole setup
    
    gamma = float(args['gamma'])  # Discount factor for past rewards
    max_episode = int(args['max_episode'])
    max_steps_per_episode = int(args['max_step'])
    alpha = float(args['mu'])/500
    lambda0 = 1-float(args['mu'])
    env = hls_env(alpha,lambda0)  # Create the environment

    random_seed = int(args['random_seed'])
    seed(random_seed)
    eps = np.finfo(np.float32).eps.item()  # Smallest number such that 1.0 + eps != 1.0

    num_inputs = 210
    num_actions = 2
    num_hidden_1 = 256
    num_hidden_2 = 128

    inputs = layers.Input(shape=(num_inputs,))
    common = layers.Dense(num_hidden_1)(inputs)
    #common = layers.Dropout(0.1)(common)
    common = layers.LeakyReLU(alpha=0.3)(common)
    #common = layers.BatchNormalization()(common)

    common = layers.Dense(num_hidden_1)(common)
    #common = layers.Dropout(0.1)(common)
    common = layers.LeakyReLU(alpha=0.1)(common)
    #common = layers.BatchNormalization()(common)

    common = layers.Dense(num_hidden_2, activation="tanh")(common)
    #common = layers.BatchNormalization()(common)
    action = layers.Dense(num_actions, activation="softmax")(common)
    critic = layers.Dense(1)(common)

    model = Model(inputs=inputs, outputs=[action, critic])

    lr=float(args['lr'])
    lr_schedule = tf.keras.optimizers.schedules.ExponentialDecay(initial_learning_rate=lr,decay_steps=2000,decay_rate=0.9)
    optimizer = keras.optimizers.Adam(learning_rate=lr_schedule)

    model.compile(optimizer=optimizer)

    huber_loss = keras.losses.Huber()
    action_probs_history = []
    action_probs_history_0 = []
    action_probs_history_1=[]
    action_history = []
    critic_value_history = []
    state_history = []
    rewards_history = []
    running_reward = 0
    episode_count = 0

    # 54 graphs now
    total_graphs=54
    num_per_dsp=2

    solution_mark=dict()
    solution_set=dict()

    fp=open('graph_index_dsp_target','rb')
    g_ind_dsp_tar=pickle.load(fp)
    total_trials=len(g_ind_dsp_tar)
    # exploration rate
    epsilon=0.1
    ff=0
    p00=[0.1,0.9]

    for i in range(max_episode):
        ind=int(np.remainder(np.floor(i/num_per_dsp),total_trials))
        graph_index=int(g_ind_dsp_tar[ind][0])
        dsp_target=int(g_ind_dsp_tar[ind][1])
        
        state = env.reset(graph_index,dsp_target)
        episode_reward = 0
        if i>1500 and ff==0:
            epsilon=epsilon/2
            ff=1

        for timestep in range(1, max_steps_per_episode):

            state = tf.convert_to_tensor(state)
            state = tf.expand_dims(state, 0)

            # Predict action probabilities and estimated future rewards
            # from environment state
            action_probs, critic_value = model(state)
        
            state_history.append(state)

            # Sample action from action probability distribution
            if np.random.rand()>(1-epsilon):
                action=np.random.choice(num_actions, p=[0.5,0.5])
                action_probs_history_0.append(tf.clip_by_value(action_probs[0, action],1e-15,1.0))
            elif env.non_assigned_counter>=2*env.target_dsp+10:
                action=np.random.choice(num_actions, p=[0.1,0.9])
                action_probs_history_0.append(p00[action])
            else:
                pp=np.squeeze(action_probs)
                action = np.random.choice(num_actions, p=pp)
                action_probs_history_0.append(tf.clip_by_value(action_probs[0, action],1e-15,1.0))
            action_probs_history_1.append(tf.clip_by_value(action_probs[0, action],1e-15,1.0))
            action_history.append(action)

            # Apply the sampled action in our environment
            state, reward, done, lut, dsp, cp = env.step(action)
            rewards_history.append(reward)

            episode_reward += reward

            if done:
                break

        # Update running reward to check condition for solving
        print(lut, dsp, cp)
        ah=action_history.copy()
        if (graph_index,int(dsp)) in solution_mark:
            if len(solution_mark[graph_index,int(dsp)])==5:
                if lut<max(solution_mark[graph_index,int(dsp)]):
                    max_index=solution_mark[graph_index,int(dsp)].index(max(solution_mark[graph_index,int(dsp)]))
                    solution_mark[graph_index,int(dsp)].pop(max_index)
                    solution_set[graph_index,int(dsp)].pop(max_index)
                    solution_mark[graph_index,int(dsp)].append(int(lut))
                    solution_set[graph_index,int(dsp)].append(ah)
            else:
                solution_mark[graph_index,int(dsp)].append(int(lut))
                solution_set[graph_index,int(dsp)].append(ah)
        else:
            solution_mark[graph_index,int(dsp)]=[int(lut)]
            solution_set[graph_index,int(dsp)]=[ah]


        with tf.GradientTape() as t:
            # Calculate expected value from rewards
            # - At each timestep what was the total reward received after that timestep
            # - Rewards in the past are discounted by multiplying them with gamma
            # - These are the labels for our critic
            returns = []
            discounted_sum = 0
            for r in rewards_history[::-1]:
                discounted_sum = r + gamma * discounted_sum
                returns.insert(0, discounted_sum)

            for i in range(len(state_history)):
                action_probs, critic_value = model(state_history[i])
                critic_value_history.append(critic_value[0, 0])
                p0=np.squeeze(action_probs)
                if True in np.isnan(p0):
                    p0=[0.5,0.5]
                    action_probs_history.append(tf.math.log(p0[action_history[i]]))
                else:
                    action_probs_history.append(tf.math.log(tf.clip_by_value(action_probs[0, action_history[i]],1e-15,1.0)))
                    
                    #action_probs_history.append(tf.math.log(action_probs[0, action_history[i]]))

            # Calculating loss values to update our network
            history = zip(action_probs_history, critic_value_history, returns, action_probs_history_0, action_probs_history_1)
            actor_losses = []
            critic_losses = []
            for log_prob, value, ret, pi0, pi1 in history:
                diff = ret - value
                actor_losses.append( - log_prob * diff * pi1/pi0)  # actor loss

                critic_losses.append(
                    huber_loss(tf.expand_dims(value, 0), tf.expand_dims(ret, 0))
                )

            # Backpropagation
            loss_value = sum(actor_losses) + sum(critic_losses)
            grads = t.gradient(loss_value, model.trainable_variables)
            #grads = [(tf.clip_by_value(grad, -1.0, 1.0)) for grad in grads]
            optimizer.apply_gradients(zip(grads, model.trainable_variables))
        
            # Clear the loss and reward history
            action_probs_history.clear()
            action_history.clear()
            action_probs_history_0.clear()
            action_probs_history_1.clear()
            critic_value_history.clear()
            rewards_history.clear()
            state_history.clear()

        episode_count += 1
    

    model.save('ac_mu_'+str(int(10*float(args['mu'])))+'_model_rs_'+str(random_seed)+'.h5')
    with open('ac_mu_'+str(int(10*float(args['mu'])))+'_solution_'+str(random_seed), 'wb') as fp:
        pickle.dump([solution_mark,solution_set], fp)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for the actor critic')

    parser.add_argument('--max-episode', help='the number of max episodes', default=9000)
    parser.add_argument('--max-step', help='max steps per episode', default=10000)
    parser.add_argument('--mu', help='the importance of LUT in optimization', default=0.5)
    parser.add_argument('--gamma', help='the discount factor', default=0.95)
    parser.add_argument('--random-seed', help='the random number seed', default=100)
    parser.add_argument('--lr', help='the learning rate', default=0.01)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)