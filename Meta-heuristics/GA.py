import numpy as np
import random

import argparse
import pprint as pp

import os

os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

def get_initial_population(length, population_size):
    chromsomes = [0 for i in range(population_size)]
    for i in range(population_size):
        chromsomes[i]= list(np.random.randint(0, 2, length))
    return chromsomes


def get_cumulative_prob(fitness_value_array):
    popusize=len(fitness_value_array)
    # get the max cost
    max_value = np.max(fitness_value_array)
    adjusted_fitness_value=np.ones([1,len(fitness_value_array)],dtype=np.int)*max_value-fitness_value_array
    # the smaller cost, the larger prob to be chosen
    probability = np.divide(adjusted_fitness_value,np.sum(adjusted_fitness_value))
    # cummulative probability for evolvement
    cum_probability = np.cumsum(probability)
    return cum_probability


def select_new_population(parent_size, population, cum_probability):
    # get parents for mating
    m = parent_size
    n = len(population)
    # initialize new population
    new_population = [0 for i in range(m)]
    for i in range(m):
        # generate a random number between 0 and 1
        randomnum = np.random.random()
        # make selections with cum prob
        for j in range(n):
            if randomnum < cum_probability[j]:
                new_population[i]=population[j]
                break
    return new_population


def cross_new_population(newpopu, length, prob):
    m = len(newpopu)
    n = length # length of each chromsome
    numbers = np.uint8(m * prob)
    if numbers % 2 != 0:
        numbers = numbers + 1
    # initialize new crossover population
    update_population = [0 for i in range(m)]
    # randomly generate indexes of chromsomes for crossover
    index = random.sample(range(m), numbers)
    # copy non-crossover chromes to new population directly
    for i in range(m):
        if not index.__contains__(i):
            update_population[i] = newpopu[i]
    # cross
    j = 0
    while j < numbers:
        # randomly generate a cross point, np.random.randint() returns a list
        crosspoint = np.random.randint(0, n, 1)
        cross_point = crosspoint[0]

        a = [0 for i in range(n)]
        b = [0 for i in range(n)]

        a[0:cross_point] = newpopu[index[j]][0:cross_point]
        a[cross_point:] = newpopu[index[j+1]][cross_point:]
        b[0:cross_point] = newpopu[index[j+1]][0:cross_point]
        b[cross_point:] = newpopu[index[j]][cross_point:]

        update_population[index[j]] = a
        update_population[index[j+1]] = b
        j = j + 2
    return update_population


def mutation(cross_population, length, mutaprob):
    # initialization
    mutationpopu = cross_population[:]
    m = len(cross_population)
    n = length # length of the chromesome
    # calculate the number of genes for mutation
    mutationnums = np.uint8(m * n * mutaprob)
    # randomly generate mutation positions
    mutationindex = random.sample(range(m * n), mutationnums)
    # mutations
    for geneindex in mutationindex:
        row = np.uint8(np.floor(geneindex / n))
        colume = geneindex % n
        if mutationpopu[row][colume] == 0:
            mutationpopu[row][colume] = 1
        else:
            mutationpopu[row][colume] = 0
    return mutationpopu


import pandas as pd

import stellargraph as sg
from stellargraph.mapper import PaddedGraphGenerator
from stellargraph import StellarGraph
from stellargraph.layer import GraphConvolution

from tensorflow.keras.models import load_model
import tensorflow as tf

import pickle

gamma=1 # parameter for critical path optimization

# get graph edge and plain node information
fp=open('info_edge','rb')
edge=pickle.load(fp)
fp=open('info_plain_graph','rb')
plain_graph=pickle.load(fp)
    
fp=open('multiplication_index','rb')
multiplication_index=pickle.load(fp)

model_proxy_lut=load_model('model_proxy_lut.h5',custom_objects={'GraphConvolution': GraphConvolution})
model_proxy_dsp=load_model('model_proxy_dsp.h5',custom_objects={'GraphConvolution': GraphConvolution})
model_proxy_cp=load_model('model_proxy_cp.h5',custom_objects={'GraphConvolution': GraphConvolution})


def cost_function(population,graph_index,dsp_target,mu):
    current_nodes=plain_graph[graph_index].copy()
    current_multiplications=multiplication_index[graph_index]
    current_edge=edge[graph_index]

    graphs=[0 for i in range(len(population))]
    for i in range(len(population)):
        for j in range(len(current_multiplications)):
            if population[i][j]==1:
                current_nodes['f10'][current_multiplications[j]]=10
        current_graph=StellarGraph(current_nodes,current_edge)
        graphs[i]=current_graph
        current_nodes=plain_graph[graph_index].copy()
    
    generator=PaddedGraphGenerator(graphs=graphs)
    mapper=generator.flow([i for i in range(len(graphs))])
    lut=np.round(model_proxy_lut.predict(mapper))
    dsp=np.round(model_proxy_dsp.predict(mapper))
    cp=model_proxy_cp.predict(mapper)

    cost=[0 for i in range(len(dsp))]
    for i in range(len(dsp)):
        if dsp[i][0]>dsp_target:
            cost[i]=mu*lut[i][0]/500+10*np.abs(dsp[i][0]-dsp_target)+(1-mu)*cp[i][0]
        else:
            cost[i]=mu*lut[i][0]/500+3*(dsp[i][0]-dsp_target)+(1-mu)*cp[i][0]
    return cost


def get_cost_sorted(cost):
    index=[0 for i in range(len(cost))]
    cc=cost.copy()
    for i in range(len(cc)):
        index[i] = cc.index(min(cc))
        cc[cc.index(min(cc))] = max(cc)+1
    return index


def main(args):
    population_size=int(args['population'])

    gamma=1 # parameter for critical path optimization
    graph_index=int(args['graph_index'])
    dsp_target=int(args['dsp_target'])
    length=len(multiplication_index[graph_index])

    parent_size=int(args['parent_size'])
    cross_prob=float(args['cross_prob'])
    mutation_prob=float(args['mutation_prob'])

    population=get_initial_population(length, population_size)
    max_generation=int(args['max_generation'])

    mu=float(args['mu'])

    for i in range(max_generation):
        cost=cost_function(population,graph_index,dsp_target,mu)
        cum_prob=get_cumulative_prob(cost)
        new_population=select_new_population(parent_size, population, cum_prob)
        cross_population=cross_new_population(new_population, length, cross_prob)
        mutation_population=mutation(cross_population, length, mutation_prob)
        population=new_population+mutation_population
        #print(population)
    
    cost=cost_function(population,graph_index,dsp_target,mu)
    ind=get_cost_sorted(cost)

    #print(ind)
    final_population=[0 for i in range(10)]
    for i in range(5):
        final_population[i]=population[ind[i]]
    with open('GA/GA_mu_'+str(int(10*float(args['mu'])))+'_graph_'+str(graph_index)+'_dsp_'+str(dsp_target), 'wb') as fp:
        pickle.dump(final_population, fp)
    return ind,population


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for the genetic algorithm')

    parser.add_argument('--max-generation', help='the number of max generations', default=20)
    parser.add_argument('--population', help='the population of each generation', default=40)
    parser.add_argument('--parent-size', help='the number of parents for mating in each generation', default=20)
    parser.add_argument('--cross-prob', help='the probability for crossover', default=0.6)
    parser.add_argument('--mutation-prob', help='the probability for gene mutation', default=0.01)
    

    parser.add_argument('--graph-index', help='the index of currently searching graph', default=1)
    parser.add_argument('--dsp-target', help='the number of target dsps', default=2)
    parser.add_argument('--mu', help='the importance of LUT in optimization', default=0.5)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)