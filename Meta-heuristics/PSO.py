import random
import math

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
import numpy as np


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

#--- COST FUNCTION ------------------------------------------------------------+

# function we are attempting to optimize (minimize)
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
    cp=model_proxy_cp.predict(generator.flow([0]))[0][0]

    if dsp>=dsp_target:
        cost=mu*lut/500+10*np.abs(dsp-dsp_target)+(1-mu)*cp
    else:
        cost=mu*lut/500+3*np.abs(dsp-dsp_target)+(1-mu)*cp
    return cost

#--- MAIN ---------------------------------------------------------------------+

class Particle:
    def __init__(self,x0):
        self.position_i=[]          # particle position
        self.velocity_i=[]          # particle velocity
        self.pos_best_i=[]          # best position individual
        self.err_best_i=-1          # best error individual
        self.err_i=-1               # error individual

        for i in range(0,num_dimensions):
            self.velocity_i.append(random.uniform(-1,1))
            self.position_i.append(x0[i])

    # evaluate current fitness
    def evaluate(self,costFunc,graph_index,dsp_target,mu):
        self.err_i=costFunc(graph_index, dsp_target, self.position_i, mu)

        # check to see if the current position is an individual best
        if self.err_i < self.err_best_i or self.err_best_i==-1:
            self.pos_best_i=self.position_i.copy()
            self.err_best_i=self.err_i

    # update new particle velocity
    def update_velocity(self,pos_best_g):
        w=0.5       # constant inertia weight (how much to weigh the previous velocity)
        c1=2        # cognative constant
        c2=2        # social constant

        for i in range(0,num_dimensions):
            r1=random.random()
            r2=random.random()

            vel_cognitive=c1*r1*(self.pos_best_i[i]-self.position_i[i])
            vel_social=c2*r2*(pos_best_g[i]-self.position_i[i])
            self.velocity_i[i]=w*self.velocity_i[i]+vel_cognitive+vel_social

    # update the particle position based off new velocity updates
    def update_position(self,bounds):
        for i in range(0,num_dimensions):
            self.position_i[i]=self.position_i[i]+self.velocity_i[i]

            # adjust maximum position if necessary
            if self.position_i[i]>bounds[i][1]:
                self.position_i[i]=bounds[i][1]

            # adjust minimum position if neseccary
            if self.position_i[i] < bounds[i][0]:
                self.position_i[i]=bounds[i][0]

            self.position_i[i]=int(np.round(self.position_i[i]))


class PSO():
    def __init__(self,costFunc,graph_index,dsp_target,mu,x0,bounds,num_particles,maxiter):
        global num_dimensions

        num_dimensions=len(x0[0])       # get the length of multiplications
        err_best_g=-1                   # best error for group
        pos_best_g=[]                   # best position for group

        solution_set=[]
        cost_set=[]

        # establish the swarm
        swarm=[]
        for i in range(0,num_particles):
            swarm.append(Particle(x0[i]))

        # begin optimization loop
        i=0
        while i < maxiter:
            # print i,err_best_g
            # cycle through particles in swarm and evaluate fitness
            for j in range(0,num_particles):
                swarm[j].evaluate(costFunc,graph_index,dsp_target,mu)

                # determine if current particle is the best (globally)
                if swarm[j].err_i < err_best_g or err_best_g == -1:
                    pos_best_g=list(swarm[j].position_i).copy()
                    err_best_g=float(swarm[j].err_i)

                    if len(solution_set)==3:
                        max_index=cost_set.index(max(cost_set))
                        cost_set.pop(max_index)
                        solution_set.pop(max_index)
                        cost_set.append(swarm[j].err_i)
                        ss=swarm[j].position_i.copy()
                        solution_set.append(ss)
                    else:
                        cost_set.append(swarm[j].err_i)
                        ss=swarm[j].position_i.copy()
                        solution_set.append(ss)

            # cycle through swarm and update velocities and position
            for j in range(0,num_particles):
                swarm[j].update_velocity(pos_best_g)
                swarm[j].update_position(bounds)
            i+=1

        # print final results
        #print ('FINAL:')
        #print (pos_best_g)
        #print (err_best_g)
        #print(solution_set)

        with open('PSO/PSO_mu_'+str(int(10*mu))+'_graph_'+str(graph_index)+'_dsp_'+str(dsp_target), 'wb') as fp:
            pickle.dump(solution_set, fp) 

def main(args):
    #--- RUN ----------------------------------------------------------------------+


    graph_index=int(args['graph_index'])
    dsp_target=int(args['dsp_target'])
    mu=float(args['mu'])

    num_particles=int(args['num_particles'])
    maxiter=int(args['maxiter'])

    length=len(multiplication_index[graph_index])

    initial_positions = [0 for i in range(num_particles)] # initial starting location for all particles
    for i in range(num_particles):
        initial_positions[i]=list(np.random.randint(0, 2, length))

    bounds=[(0,1) for i in range(length)]  # input bounds [(x1_min,x1_max),(x2_min,x2_max)...]

    PSO(cost_function,graph_index,dsp_target,mu,initial_positions,bounds,num_particles,maxiter)



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='provide arguments for particle swarm optimization')

    parser.add_argument('--num-particles', help='the number of particles', default=20)
    parser.add_argument('--maxiter', help='maxiterations', default=40)
    
    parser.add_argument('--graph-index', help='the index of currently searching graph', default=5)
    parser.add_argument('--dsp-target', help='the number of target dsps', default=10)
    parser.add_argument('--mu', help='the importance of LUT in optimization', default=0.5)

    args = vars(parser.parse_args())
    pp.pprint(args)
    main(args)