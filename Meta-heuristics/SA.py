import numpy as np
import random

import os

os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

import pandas as pd

import argparse
import pprint as pp

import stellargraph as sg
from stellargraph.mapper import PaddedGraphGenerator
from stellargraph import StellarGraph
from stellargraph.layer import GraphConvolution

from tensorflow.keras.models import load_model
import tensorflow as tf

import pickle

gamma=1 # parameter for critical path optimization

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


def cost_function(graph_index, dsp_target, directives,mu):
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
    cp=model_proxy_cp.predict(generator.flow([0]))[0][0]

    if dsp>=dsp_target:
        cost=mu*lut/500+10*np.abs(dsp-dsp_target)+(1-mu)*cp
    else:
        cost=mu*lut/500+3*(dsp-dsp_target)+(1-mu)*cp
    return cost


def mutation(directives, mutaprob):
    n=len(directives)
    muta_dir=directives[:]
    # calculate the number of mutations
    mutationnums = np.uint8(n * mutaprob)
    # randomly generate mutation positions
    mutationindex = random.sample(range(n), mutationnums)
    # mutations
    for index in mutationindex:
        if muta_dir[index] == 0:
            muta_dir[index] = 1
        else:
            muta_dir[index] = 0
    return muta_dir



def main(args):
    graph_index=int(args['graph_index'])
    dsp_target=int(args['dsp_target'])
    mu=float(args['mu'])
    length=len(multiplication_index[graph_index])
    d0=list(np.random.randint(0, 2, length))

    #initialization
    t0=cost_function(graph_index, dsp_target, d0, mu)
    local_d0=d0[:] #local optimum

    T0=int(args['t0'])
    Tend=int(args['tend'])
    a=float(args['alpha']) # cool down parameter
    Lk=int(args['Lk'])

    mutation_prob=float(args['mutation_prob'])
    solution_set=[]
    cost_set=[]
    cost_mark=t0

    while T0>Tend:
        for i in range(Lk):
            # generate a neighbor directives
            d_new=mutation(d0,mutation_prob) 
            t_new=cost_function(graph_index, dsp_target, d_new, mu)
        
            delta_t=t_new-t0
        
            if delta_t<0: # accept
                d0=d_new[:]
                t0=t_new
                if t_new<cost_mark:
                    local_d0=d0[:]
                    cost_mark=t_new
            elif np.random.random()<np.exp(-delta_t/T0):
                d0=d_new[:]
                t0=t_new
    
        if len(solution_set)==5:
            max_index=cost_set.index(max(cost_set))
            cost_set.pop(max_index)
            solution_set.pop(max_index)
            cost_set.append(cost_mark)
            solution_set.append(local_d0)
        else:
            cost_set.append(cost_mark)
            solution_set.append(local_d0)
    
        d0=local_d0[:]
        T0=T0*a

    #print(cost_set)
    import pickle
    with open('SA/SA_mu_'+str(int(10*float(args['mu'])))+'_graph_'+str(graph_index)+'_dsp_'+str(dsp_target), 'wb') as fp:
        pickle.dump(solution_set, fp) 


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for the genetic algorithm')

    parser.add_argument('--t0', help='initial temperature', default=1000)
    parser.add_argument('--tend', help='end temperature', default=669)
    parser.add_argument('--alpha', help='cool down factor', default=0.99)
    parser.add_argument('--Lk', help='length of one iteration', default=20)
    parser.add_argument('--mutation-prob', help='the probability for mutation', default=0.1)
    
    parser.add_argument('--graph-index', help='the index of currently searching graph', default=1)
    parser.add_argument('--dsp-target', help='the number of target dsps', default=2)
    parser.add_argument('--mu', help='the importance of LUT in optimization', default=0.5)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)