import pandas as pd
import os

os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

import stellargraph as sg
from stellargraph.mapper import PaddedGraphGenerator
from stellargraph import StellarGraph
from stellargraph.layer import GraphConvolution

from tensorflow.keras.models import load_model
import tensorflow as tf

import pickle
import numpy as np


import argparse
import pprint as pp




# get graph edge and plain node information, and metadata
fp=open('info_edge','rb')
edge=pickle.load(fp)
fp=open('info_plain_graph','rb')
plain_graph=pickle.load(fp)
    
fp=open('multiplication_index','rb')
multiplication_index=pickle.load(fp)

model_proxy_lut=load_model('model_proxy_lut.h5',custom_objects={'GraphConvolution': GraphConvolution})
model_proxy_dsp=load_model('model_proxy_dsp.h5',custom_objects={'GraphConvolution': GraphConvolution})
model_proxy_cp=load_model('model_proxy_cp.h5',custom_objects={'GraphConvolution': GraphConvolution})


def cost_function(graph_index, dsp_target, directives, mu):
    current_nodes=plain_graph[graph_index].copy()
    current_multiplications=multiplication_index[graph_index]
    current_edge=edge[graph_index]

    for i in range(len(current_multiplications)):
        if directives[i]==1:
            current_nodes['f10'][current_multiplications[i]]=10
    current_graph=StellarGraph(current_nodes,current_edge)
    generator=PaddedGraphGenerator(graphs=[current_graph])

    lut=np.round(model_proxy_lut.predict(generator.flow([0]))[0][0])
    dsp=np.round(model_proxy_dsp.predict(generator.flow([0]))[0][0])
    cp=model_proxy_dsp.predict(generator.flow([0]))[0][0]

    if dsp>=dsp_target:
        cost=mu*lut/500+10*np.abs(dsp-dsp_target)+(1-mu)*cp
    else:
        cost=mu*lut/500+3*np.abs(dsp-dsp_target)+(1-mu)*cp
    return cost


def get_cost_sorted(cost):
    index=[0 for i in range(len(cost))]
    cc=cost.copy()
    for i in range(len(cc)):
        index[i] = cc.index(min(cc))
        cc[cc.index(min(cc))] = max(cc)+1
    return index


def ACO(ants, num_ants, rho, length, max_iter, dsp_target, mu, graph_index, cost_function):
    solution_set=[]
    cost_set=[]

    ant_cost = [0 for i in range(num_ants)]
    for i in range(num_ants):
        ant_cost[i] = cost_function(graph_index, dsp_target, ants[i], mu) # compute the cost of each ant

    c = [[set(), set()] for i in range(length)] # initial cost for different ops on each multiplication

    # initialize tau and P
    tau = [[0.5, 0.5] for i in range(length)]
    P = [[0.5, 0.5] for i in range(length)]

    # collect costs to compute epsilon
    for i in range(length):
        for j in range(num_ants):
            if ants[j][i] == 0:
                c[i][0].add(ant_cost[j])
            else:
                c[i][1].add(ant_cost[j])

    # initialize epsilon
    epsilon = []
    for i in range(length):
        local_c = c[i]
        if not local_c[0]:
            e0 = 0
        else:
            e0 = 1/np.mean(list(local_c[0]))
        
        if not local_c[1]:
            e1 = 0
        else:
            e1 = 1/np.mean(list(local_c[1]))

        epsilon.append([e0, e1])

    # iteration
    for k in range(max_iter):
        # update tau
        for i in range(length):
            tau[i] = np.add(np.multiply(tau[i],1 - rho), epsilon[i])
            P[i][0] = tau[i][0] / (tau[i][0] + tau[i][1])
            P[i][1] = tau[i][1] / (tau[i][0] + tau[i][1])

            P[i][0], P[i][1] = P[i][0] / (P[i][0] + P[i][1]), P[i][1] / (P[i][0] + P[i][1])
            
        # update each ant
        for i in range(num_ants):
            for j in range(length):
                action = np.random.choice(2, p=P[j])
                ants[i][j] = action

        # update cost
        for i in range(num_ants):
            ant_cost[i] = cost_function(graph_index, dsp_target, ants[i], mu) # compute the cost of each ant

        for i in range(length):
            for j in range(num_ants):
                if ants[j][i] == 0:
                    c[i][0].add(ant_cost[j])
                else:
                    c[i][1].add(ant_cost[j])

        for i in range(length):
            local_c = c[i]
            if not local_c[0]:
                e0 = 0
            else:
                e0 = 1/np.mean(list(local_c[0]))
            if not local_c[1]:
                e1 = 0
            else:
                e1 = 1/np.mean(list(local_c[1]))
            epsilon[i] = [e0, e1]

        #print(ant_cost)

    
    ind=get_cost_sorted(ant_cost)

    #print(ind)
    final_ant=[0 for i in range(5)]
    for i in range(5):
        final_ant[i]=ants[ind[i]]
    with open('ACO/ACO_mu_'+str(int(10*float(args['mu'])))+'_graph_'+str(graph_index)+'_dsp_'+str(dsp_target), 'wb') as fp:
        pickle.dump(final_ant, fp)


def main(args):
    graph_index = int(args['graph_index'])
    dsp_target = int(args['dsp_target'])
    num_ants = 10
    max_iter = 100
    mu = float(args['mu'])
    rho = 0.1

    length=len(multiplication_index[graph_index])

    initial_ants = [0 for i in range(num_ants)] # initial ants
    for i in range(num_ants):
        initial_ants[i]=list(np.random.randint(0, 2, length))

    aco = ACO(initial_ants, num_ants, rho, length, max_iter, dsp_target, mu, graph_index, cost_function)



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for ACO')

    parser.add_argument('--graph-index', help='the index of currently searching graph', default=1)
    parser.add_argument('--dsp-target', help='the number of target dsps', default=2)
    parser.add_argument('--mu', help='the importance of LUT in optimization', default=0.5)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)