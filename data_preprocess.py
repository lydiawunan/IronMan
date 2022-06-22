# data preprocess, save as csv files

import pandas as pd
import numpy as np
import stellargraph as sg
from stellargraph import StellarGraph
import pickle

case_index=[0,3,4,5,6,7,13,14,15,16,17,18,19,20,21,22,23,24,26,27,29,30]+[i for i in range(31,44)]+[i for i in range(47,60)]+[100,101,102,103,104,105,106]
# rename stencil as case 0
# rename gemm as case 100
# rename stencil_4_4_4 as case 101
# rename stencil_less_dsp as case 102
# rename kernal_2mm as case 103
# rename kernel_durbin_smaller as case 104
# rename spmv as case 105
# rename kernal_adi as case 106


# change precision into binary numbers
def to_binary(number):
    if number==2:
        return 0,0,0,0,1
    if number==3:
        return 0,0,0,1,0
    if number==4:
        return 0,0,0,1,1
    if number==5:
        return 0,0,1,0,0
    if number==6:
        return 0,0,1,0,1
    if number==7:
        return 0,0,1,1,0
    if number==8:
        return 0,0,1,1,1
    if number==9:
        return 0,1,0,0,0
    if number==10:
        return 0,1,0,0,1
    if number==11:
        return 0,1,0,1,0
    if number==12:
        return 0,1,0,1,1
    if number==13:
        return 0,1,1,0,0
    if number==14:
        return 0,1,1,0,1
    if number==15:
        return 0,1,1,1,0
    if number==16:
        return 0,1,1,1,1 
    if number==32:
        return 1,1,1,1,1  

LUT_target=[]
DSP_target=[]
CP_target=[]
multi_dir=[]

for k in range(len(case_index)):
    name='DATASET/case_'+str(case_index[k])+'/DFG_case_'+str(case_index[k])+'.txt'
    f = open(name, "r")
    lines = f.readlines()
    print(case_index[k])

    # get graph information
    node_name=[] # starts from 1
    #[input, intermediate_add, intermediate_multiply, output, precision in bits, whether need to set directives, whether assigned directives]
    node_features=[] 
    edge_source=[]
    edge_end=[]
    edge_count=0
    input_node=0
    inter_node=0
    out_node=0
    node_count=0
    node_dir=[] # starts from 0 -> index n-1 for node n, mark multiplication node
    node_number_mapping=dict() # for intermediate node name translate, in case the node sequencing is not continuous

    for i in range(len(lines)):
        # get input nodes
        if lines[i][0:2]=='in' and 'm' not in lines[i] and 'o' not in lines[i]:
            input_node=input_node+1
            node_count=node_count+1
            if lines[i][3]==' ':
                node_name=node_name+[lines[i][0:3]]
                precision=int(lines[i][7:9])
                p_binary=to_binary(precision)
                node_features=node_features+[[1,0,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
            elif lines[i][4]==' ':
                node_name=node_name+[lines[i][0:4]]
                precision=int(lines[i][8:10])
                p_binary=to_binary(precision)
                node_features=node_features+[[1,0,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
            elif lines[i][5]==' ':
                node_name=node_name+[lines[i][0:5]]
                precision=int(lines[i][9:11])
                p_binary=to_binary(precision)
                node_features=node_features+[[1,0,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
            else:
                node_name=node_name+[lines[i][0:6]]
                precision=int(lines[i][10:12])
                p_binary=to_binary(precision)
                node_features=node_features+[[1,0,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
        # get intermediate nodes
        if lines[i][0]=='m' and ('*' in lines[i] or '+' in lines[i]):
            node_count=node_count+1
            inter_node=inter_node+1
            if lines[i][2]==' ' and lines[i][4]==' ':
                node_name=node_name+[lines[i][0:2]]
                precision=int(lines[i][8:10])
                p_binary=to_binary(precision)
                if lines[i][4]=='+':
                    node_features=node_features+[[0,1,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
                else:
                    node_features=node_features+[[0,0,1,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],1,0]]
                    node_dir=node_dir+[node_count-1]
                node_number_mapping[int(lines[i][1:2])]=node_count-1
            if lines[i][3]==' ' and lines[i][5]==' ':
                node_name=node_name+[lines[i][0:3]]
                precision=int(lines[i][9:11])
                p_binary=to_binary(precision)
                if lines[i][4]=='+':
                    node_features=node_features+[[0,1,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
                else:
                    node_features=node_features+[[0,0,1,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],1,0]]
                    node_dir=node_dir+[node_count-1]
                node_number_mapping[int(lines[i][1:3])]=node_count-1
            if lines[i][4]==' ' and lines[i][2]!=' ':
                node_name=node_name+[lines[i][0:4]]
                precision=int(lines[i][10:12])
                p_binary=to_binary(precision)
                if lines[i][5]=='+':
                    node_features=node_features+[[0,1,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
                else:
                    node_features=node_features+[[0,0,1,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],1,0]]
                    node_dir=node_dir+[node_count-1]
                node_number_mapping[int(lines[i][1:4])]=node_count-1
            if lines[i][5]==' ' and lines[i][3]!=' ':
                node_name=node_name+[lines[i][0:5]]
                precision=int(lines[i][11:13])
                p_binary=to_binary(precision)
                if lines[i][6]=='+':
                    node_features=node_features+[[0,1,0,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],0,0]]
                else:
                    node_features=node_features+[[0,0,1,0,p_binary[0],p_binary[1],p_binary[2],p_binary[3],p_binary[4],1,0]]
                    node_dir=node_dir+[node_count-1]
                node_number_mapping[int(lines[i][1:5])]=node_count-1
        # get output nodes
        if lines[i][0]=='o':
            node_count=node_count+1
            out_node=out_node+1
            if lines[i][3]=='\n':
                node_name=node_name+[lines[i][0:3]]
            elif lines[i][4]=='\n':
                node_name=node_name+[lines[i][0:4]] 
            else:
                node_name=node_name+[lines[i][0:5]] 
            node_features=node_features+[[0,0,0,1,0,0,0,0,0,0,0]] 
        # get edge information
        if (lines[i][0:2]=='in' and 'm' in lines[i]) or \
            (lines[i][0:2]=='in' and 'o' in lines[i]) or \
            (lines[i][0]=='m' and ('+' not in lines[i] and '*' not in lines[i])):
            edge_count=edge_count+1
            if lines[i][2]==' ':
                edge_source=edge_source+[lines[i][0:2]]
                if len(lines[i])==6:
                    edge_end=edge_end+[lines[i][3:5]]
                elif len(lines[i])==7:
                    edge_end=edge_end+[lines[i][3:6]]
                else:
                    edge_end=edge_end+[lines[i][3:7]]
            if lines[i][3]==' ':
                edge_source=edge_source+[lines[i][0:3]]
                if len(lines[i])==7:
                    edge_end=edge_end+[lines[i][4:6]]
                elif len(lines[i])==8:
                    edge_end=edge_end+[lines[i][4:7]]
                else:
                    edge_end=edge_end+[lines[i][4:8]]
            if lines[i][4]==' ':
                edge_source=edge_source+[lines[i][0:4]]
                if len(lines[i])==8:
                    edge_end=edge_end+[lines[i][5:7]]
                elif len(lines[i])==9:
                    edge_end=edge_end+[lines[i][5:8]]
                else:
                    edge_end=edge_end+[lines[i][5:9]]
            if lines[i][5]==' ':
                edge_source=edge_source+[lines[i][0:5]]
                if len(lines[i])==9:
                    edge_end=edge_end+[lines[i][6:8]]
                elif len(lines[i])==10:
                    edge_end=edge_end+[lines[i][6:9]]
                elif len(lines[i])==11:
                    edge_end=edge_end+[lines[i][6:10]]
                else:
                    edge_end=edge_end+[lines[i][6:11]]
            if len(lines[i])>6 and lines[i][6]==' ':
                edge_source=edge_source+[lines[i][0:6]]
                if len(lines[i])==10:
                    edge_end=edge_end+[lines[i][7:9]]
                elif len(lines[i])==11:
                    edge_end=edge_end+[lines[i][7:10]]
                elif len(lines[i])==12:
                    edge_end=edge_end+[lines[i][7:11]]
                else:
                    edge_end=edge_end+[lines[i][7:12]]

    node_dir_set=set(node_dir)
    # save edge information
    edge_data = pd.DataFrame({'source':edge_source,'target':edge_end})
    edge_data.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_edge.csv',index=False)

    # save meta data, input nodes, intermediate nodes, output nodes, number of multiplications, number of edges
    meta_data = pd.DataFrame({'input':[input_node],'inter':[inter_node],'output':[out_node],'mul':[len(node_dir)],'edge':[edge_count]})
    meta_data.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_metadata.csv',index=False)
    multi_dir.append(node_dir)

    # get directives, targets
    case=pd.read_json(r'DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_all_data.json')
    LUT_number=case.iloc[1]
    DSP_number=case.iloc[3]
    CP_number=case.iloc[6]
    LUT_op=case.iloc[2]

    LUT=[0 for i in range(len(LUT_number))]
    DSP=[0 for i in range(len(LUT_number))]
    CP=[0 for i in range(len(CP_number))]
    LUT_dir=[0 for i in range(len(CP_number))]
    for i in range(len(LUT_number)):
        LUT[i]=LUT_number[i]
        DSP[i]=DSP_number[i]
        CP[i]=CP_number[i]
        LUT_dir[i]=LUT_op[i]

    # save targets
    graph_target_lut=pd.DataFrame(LUT)
    graph_target_dsp=pd.DataFrame(DSP)
    graph_target_cp=pd.DataFrame(CP)
    graph_target_lut.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_target_lut.csv',index=False)
    graph_target_dsp.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_target_dsp.csv',index=False)
    graph_target_cp.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_target_cp.csv',index=False)
    LUT_target=LUT_target+LUT
    DSP_target=DSP_target+DSP
    CP_target=CP_target+CP
    
    
    df=pd.DataFrame({'id':node_name})
    f0=[0 for i in range(len(node_features))]
    f1=[0 for i in range(len(node_features))]
    f2=[0 for i in range(len(node_features))]
    f3=[0 for i in range(len(node_features))]
    f4=[0 for i in range(len(node_features))]
    f5=[0 for i in range(len(node_features))]
    f6=[0 for i in range(len(node_features))]
    f7=[0 for i in range(len(node_features))]
    f8=[0 for i in range(len(node_features))]
    f9=[0 for i in range(len(node_features))]
    f10=[0 for i in range(len(node_features))]

    for i in range(len(node_features)):
        f0[i]=node_features[i][0]
        f1[i]=node_features[i][1]
        f2[i]=node_features[i][2]
        f3[i]=node_features[i][3]
        f4[i]=node_features[i][4]
        f5[i]=node_features[i][5]
        f6[i]=node_features[i][6]
        f7[i]=node_features[i][7]
        f8[i]=node_features[i][8]
        f9[i]=node_features[i][9]

    df['f0']=f0
    df['f1']=f1
    df['f2']=f2
    df['f3']=f3
    df['f4']=f4
    df['f5']=f5
    df['f6']=f6
    df['f7']=f7
    df['f8']=f8
    df['f9']=f9
    df['f10']=f10
    # save plain graphs (with no directives)
    df.to_csv('DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_plain.csv',index=False)
    if case_index[k] in [100,101,103,104,105,106]:
        with open('info_case_'+str(case_index[k])+'_node_number_mapping', 'wb') as fp:
            pickle.dump(node_number_mapping, fp)

    # save graphs with different directives
    for i in range(len(LUT_dir)):
        solution=LUT_dir[i]
        f10=[0 for i in range(len(node_features))]
        for j in range(len(solution)):
            index=node_number_mapping[solution[j]]
            if index in node_dir_set:
                f10[index]=10
        df['f10']=f10
        df.to_csv('DATASET/case_'+str(case_index[k])+'/case'+str(case_index[k])+'_'+str(i)+'.csv',index=False)

# save targets together
lut_target_pd=pd.DataFrame({'LUT':LUT_target})
dsp_target_pd=pd.DataFrame({'DSP':DSP_target})
cp_target_pd=pd.DataFrame({'CP':CP_target})
lut_target_pd.to_csv('GPP/graph_target_lut.csv',index=False)
dsp_target_pd.to_csv('GPP/graph_target_dsp.csv',index=False)
cp_target_pd.to_csv('GPP/graph_target_cp.csv',index=False)

# save edge information, plain graphs, and metadata into one file
edge=[0 for k in range(len(case_index))]
plain_graph=[0 for k in range(len(case_index))]
metadata=[0 for k in range(len(case_index))]

for k in range(len(case_index)):
    name='DATASET/case_'+str(case_index[k])+'/case_'+str(case_index[k])+'_'
    edge[k]=pd.read_csv(name+'edge.csv')
    plain_graph_k=pd.read_csv(name+'plain.csv')
    plain_graph[k]=plain_graph_k.set_index("id")
    meta=pd.read_csv(name+'metadata.csv')
    metadata[k]=[int(meta['input'].values),int(meta['inter'].values),int(meta['output'].values),\
        int(meta['mul'].values),int(meta['edge'].values)]


with open('info_edge', 'wb') as fp:
    pickle.dump(edge, fp)
with open('info_plain_graph', 'wb') as fp:
    pickle.dump(plain_graph, fp)
with open('info_meta', 'wb') as fp:
    pickle.dump(metadata, fp)


# save node indexes of multiplications of each DFG
with open('multiplication_index', 'wb') as fp:
    pickle.dump(multi_dir, fp)