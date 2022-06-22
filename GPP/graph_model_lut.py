import pandas as pd
import numpy as np

import stellargraph as sg
from stellargraph.mapper import PaddedGraphGenerator
from stellargraph.layer import GCNSupervisedGraphClassification
from stellargraph import StellarGraph

from sklearn import model_selection

from tensorflow.keras import Model
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.layers import Dense,LeakyReLU,Dropout
import tensorflow as tf
import matplotlib.pyplot as plt

from tensorflow.keras.layers import Input, Dropout

from numpy.random import seed

import argparse
import pprint as pp

import pickle
fp = open('graphs_dataset','rb')
graphs = pickle.load(fp)

graph_labels_lut = pd.read_csv('graph_target_lut.csv')
graph_labels_lut = pd.get_dummies(graph_labels_lut, drop_first=True)

generator = PaddedGraphGenerator(graphs=graphs)

def create_graph_model(generator):
    gc_model = GCNSupervisedGraphClassification(
        layer_sizes=[64,128],
        activations=["relu","relu"],
        generator=generator,
        dropout=0.1
    )
    x_inp, x_out = gc_model.in_out_tensors()

    predictions1 = Dense(units=64, kernel_initializer=tf.keras.initializers.Constant(value=0.5))(x_out)
    predictions1 = Dropout(0.1)(predictions1)
    predictions1 = LeakyReLU(alpha=0.2)(predictions1)

    predictions1 = Dense(units=64, kernel_initializer=tf.keras.initializers.Constant(value=0.5))(x_out)
    predictions1 = Dropout(0.1)(predictions1)
    predictions1 = LeakyReLU(alpha=0.1)(predictions1)

    predictions2 = Dense(units=64, kernel_initializer=tf.keras.initializers.Constant(value=0.25))(predictions1)
    predictions2 = Dropout(0.1)(predictions2)
    predictions2 = LeakyReLU(alpha=0.1)(predictions2)

    predictions = Dense(units=1,activation='relu')(predictions2)

    # Let's create the Keras model and prepare it for training
    model = Model(inputs=x_inp, outputs=predictions)
    model0 = Model(inputs=x_inp, outputs=predictions2)
    lr_schedule = tf.keras.optimizers.schedules.ExponentialDecay(initial_learning_rate=0.02,decay_steps=100000,decay_rate=0.9)
    opt = Adam(learning_rate=lr_schedule)
    model.compile(optimizer=opt, loss=tf.keras.losses.MeanAbsoluteError(),metrics=["mae"])

    return model,model0



def train_fold(model, train_gen, test_gen, epochs):
    history = model.fit(train_gen, epochs=epochs, validation_data=test_gen,verbose=1, shuffle=True)
    # calculate performance on the test data and return along with history
    test_metrics = model.evaluate(test_gen, verbose=1)
    test_mae = test_metrics[model.metrics_names.index("mae")]

    return history, test_mae



def get_generators(train_index, test_index, graph_labels, batch_size):
    train_gen = generator.flow(train_index, targets=graph_labels.iloc[train_index].values, batch_size=batch_size)
    test_gen = generator.flow(test_index, targets=graph_labels.iloc[test_index].values, batch_size=batch_size)

    return train_gen, test_gen



def main(args):
    epochs = int(args['epoch']) # maximum number of training epochs
    folds = int(args['fold'])
    batch_size = int(args['batch_size'])
    seed(int(args['random_seed']))

    model, model0 = create_graph_model(generator)
    test_mae = []

    for i in range(folds):
        print(f"Training and evaluating on fold {i+1} out of {folds}...")
        train, test = model_selection.train_test_split(graph_labels_lut, train_size=0.9, test_size=None)
        train_gen, test_gen = get_generators(np.array(train.index), np.array(test.index), graph_labels_lut, batch_size=batch_size)
        history, mae = train_fold(model, train_gen, test_gen, epochs)
        test_mae.append(mae)

    model.save('model_proxy_lut.h5')
    model0.save('model_embedding_lut.h5')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for the graph embedding model with LUT predictions')

    parser.add_argument('--epoch', help='the number of epochs per fold', default=50)
    parser.add_argument('--fold', help='the number of folds', default=10)
    parser.add_argument('--batch-size', help='the size of batch', default=32)
    parser.add_argument('--random-seed', help='random seed for repeatability', default=42)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)