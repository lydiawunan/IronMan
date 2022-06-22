# generate graph dataset

import pandas as pd
import numpy as np
import stellargraph as sg
from stellargraph import StellarGraph

case_index=[0,3,4,5,6,7,13,14,15,16,17,18,19,20,21,22,23,24,26,27,29,30]+[i for i in range(31,44)]+[i for i in range(47,60)]+[100,101,102,103,104,105,106]
graphs=[]
num_graph=0
for k in range(len(case_index)):
    name='case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_'
    edge=pd.read_csv(name+'edge.csv')
    #print(case_index[k])

    graph_label=pd.read_csv(name+'target_lut.csv')
    graph_k=[0 for i in range(len(graph_label))]

    for i in range(len(graph_label)):
        raw_content = pd.read_csv('case_'+str(case_index[k])+'/case'+str(case_index[k])+'_'+str(i)+'.csv')
        content=raw_content.set_index("id")
        graph_k[i] = StellarGraph(content, edge)
    
    graphs=graphs+graph_k
    num_graph=num_graph+len(graph_label)

print(len(graphs))
print(num_graph)

import pickle
with open('GPP/graphs_dataset', 'wb') as fp:
    pickle.dump(graphs, fp)