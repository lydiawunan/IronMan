import pandas as pd
case_ind=[0,3,4,5,6,7,13,14,15,16,17,18,19,20,21,22,23,24,26,27,29,30]+[i for i in range(31,44)]+[i for i in range(47,60)]+[100,101,102,103,104,105,106]

tuples=[]
for i in range(len(case_ind)):
    name='case_'+str(case_ind[i])+'/case_'+str(case_ind[i])+'_target_dsp.csv'
    dsp_target=pd.read_csv(name)
    max_dsp=max(dsp_target.values)
    min_dsp=min(dsp_target.values)
    if max_dsp==0:
        dsp_up_range=5
        dsp_down_range=0
    elif max_dsp<30:
        dsp_up_range=min([max_dsp+5,30])
        dsp_down_range=0
    elif max_dsp>=30:
        dsp_up_range=min([max_dsp+5,60])
        dsp_down_range=10
    #elif max_dsp>=60:
    #    dsp_up_range=60
    #    dsp_down_range=15
    for j in range(int(dsp_down_range),int(dsp_up_range)):
        tuples=tuples+[[i,j]]

import random
random.shuffle(tuples)
import pickle
with open('graph_index_dsp_target', 'wb') as fp:
    pickle.dump(tuples, fp)
