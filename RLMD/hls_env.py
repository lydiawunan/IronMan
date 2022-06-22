import pandas as pd
import numpy as np

import os

os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

import stellargraph as sg
from stellargraph.mapper import PaddedGraphGenerator
from stellargraph.layer import GCNSupervisedGraphClassification
from stellargraph import StellarGraph
from stellargraph.layer import GraphConvolution

from sklearn import model_selection
from IPython.display import display, HTML

from tensorflow.keras import Model
from tensorflow.keras.optimizers import Adam, SGD
from tensorflow.keras.layers import Dense,LeakyReLU,Dropout
from tensorflow.keras import initializers
from tensorflow.keras.models import load_model
import tensorflow as tf
import matplotlib.pyplot as plt

from tensorflow.keras.layers import Input, Dropout, MaxPooling1D

import pickle

class hls_env():
    def __init__(self,alpha,lambda0):
        # parameter for critical path optimization
        self.lambda0=lambda0
        self.alpha=alpha
        # save history information
        self.history=dict()
        # get graph edge and plain node information, and metadata
        fp=open('info_edge','rb')
        self.edge=pickle.load(fp)
        fp=open('info_plain_graph','rb')
        self.plain_graph=pickle.load(fp)
        fp=open('info_meta','rb')
        self.metadata=pickle.load(fp)

        # get positions that should be assigned directives of each graph
        fp=open('multiplication_index','rb')
        self.multiplication_index=pickle.load(fp)

        # load train grpah models for embeddings and proxy rewards
        self.model_embedding_lut=load_model('model_embedding_lut.h5',custom_objects={'GraphConvolution': GraphConvolution})
        self.model_embedding_dsp=load_model('model_embedding_dsp.h5',custom_objects={'GraphConvolution': GraphConvolution})
        self.model_embedding_cp=load_model('model_embedding_cp.h5',custom_objects={'GraphConvolution': GraphConvolution})

        self.model_proxy_lut=load_model('model_proxy_lut.h5',custom_objects={'GraphConvolution': GraphConvolution})
        self.model_proxy_dsp=load_model('model_proxy_dsp.h5',custom_objects={'GraphConvolution': GraphConvolution})
        self.model_proxy_cp=load_model('model_proxy_cp.h5',custom_objects={'GraphConvolution': GraphConvolution})

        # pointer to which graph is being processed
        #self.graph_index=0

    def step(self,a):
        terminal=0
        lut=0
        cp=0
        dsp=0

        if a==0:
            self.non_assigned_counter=self.non_assigned_counter+1
            #if self.non_assigned_counter>=4*self.target_dsp+5:
             #   for i in range(self.timestep+1,self.totalstep):
             #       index=self.current_multiplications[i]
             #       self.current_nodes['f10'][index]=10
             #   self.current_graph=StellarGraph(self.current_nodes,self.edge[self.graph_index])
             #   self.generator=PaddedGraphGenerator(graphs=[self.current_graph])
             #   self.timestep=self.totalstep-1
             #   terminal=1
        else:
            index=self.current_multiplications[self.timestep]
            self.current_nodes['f10'][index]=10
            self.current_graph=StellarGraph(self.current_nodes,self.edge[self.graph_index])
            self.generator=PaddedGraphGenerator(graphs=[self.current_graph])

        if self.timestep+1==self.totalstep:
            terminal=1

        if terminal==1:
            lut=np.round(self.model_proxy_lut.predict(self.generator.flow([0]))[0][0])
            dsp=np.round(self.model_proxy_dsp.predict(self.generator.flow([0]))[0][0])
            cp=self.model_proxy_cp.predict(self.generator.flow([0]))[0][0]

            #if (self.graph_index,self.target_dsp) not in self.history:
            #    self.history[self.graph_index,self.target_dsp]=[5000,15]
            if self.graph_index not in [0,48,49,50,51,52,53,54]:
                if dsp>self.target_dsp-3:
                    r=-self.alpha*lut-10*np.abs(self.target_dsp-dsp-3)-cp*self.lambda0
                else:
                    r=-self.alpha*lut-5*np.abs(self.target_dsp-dsp-3)-cp*self.lambda0+int(self.target_dsp==dsp)*15
                r=r/10
            else:
                if dsp>self.target_dsp-10:
                    r=-self.alpha*lut/5-10*np.abs(self.target_dsp-dsp-10)-cp*self.lambda0
                else:
                    r=-self.alpha*lut/5-5*np.abs(self.target_dsp-dsp-10)-cp*self.lambda0+int(self.target_dsp==dsp)*15
                r=r/12


            lut_embedding=self.model_embedding_lut.predict(self.generator.flow([0]))
            dsp_embedding=self.model_embedding_dsp.predict(self.generator.flow([0]))
            cp_embedding=self.model_embedding_cp.predict(self.generator.flow([0]))
            s2=list(np.divide(lut_embedding[0],50))+list(np.divide(dsp_embedding[0],1))+list(np.divide(cp_embedding[0],1)) \
                + list(np.divide(self.metadata[self.graph_index],100)) \
                + [self.target_dsp/50 for i in range(10)]+[self.current_multiplications[self.timestep]/80 for i in range(3)]
        else:
            r=0
            self.timestep=self.timestep+1
            lut_embedding=self.model_embedding_lut.predict(self.generator.flow([0]))
            dsp_embedding=self.model_embedding_dsp.predict(self.generator.flow([0]))
            cp_embedding=self.model_embedding_cp.predict(self.generator.flow([0]))
            s2=list(np.divide(lut_embedding[0],50))+list(np.divide(dsp_embedding[0],1))+list(np.divide(cp_embedding[0],1)) \
                + list(np.divide(self.metadata[self.graph_index],100)) \
                + [self.target_dsp/50 for i in range(10)]+[self.current_multiplications[self.timestep]/80 for i in range(3)]

        return s2, r, terminal, lut, dsp, cp


    def reset(self,graph_index,target_dsp):
        self.graph_index=graph_index
        self.target_dsp=target_dsp

        self.current_nodes=self.plain_graph[self.graph_index].copy()
        self.current_graph=StellarGraph(self.current_nodes,self.edge[self.graph_index])
        self.current_multiplications=self.multiplication_index[self.graph_index]
        self.timestep=0
        self.totalstep=len(self.multiplication_index[self.graph_index])
        self.non_assigned_counter=0
        
        self.generator=PaddedGraphGenerator(graphs=[self.current_graph])
        mapper=self.generator.flow([0])
        lut_embedding=self.model_embedding_lut.predict(mapper)
        dsp_embedding=self.model_embedding_dsp.predict(mapper)
        cp_embedding=self.model_embedding_cp.predict(mapper)
        state=list(np.divide(lut_embedding[0],300))+list(np.divide(dsp_embedding[0],100))+list(np.divide(cp_embedding[0],100)) \
            + list(np.divide(self.metadata[self.graph_index],100)) \
            + [self.target_dsp/50 for i in range(10)]+[self.current_multiplications[self.timestep]/80 for i in range(3)]
        
        if (graph_index,target_dsp) not in self.history:
            if graph_index in [0,49,50,52,53,54]:
                self.history[graph_index,target_dsp]=[25000,10] # lut, cp
            elif graph_index in [48,51]:
                self.history[graph_index,target_dsp]=[30000,10]
            else:
                self.history[graph_index,target_dsp]=[5000,10] # lut, cp

        return state