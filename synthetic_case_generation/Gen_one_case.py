
# coding: utf-8


import random
from random import sample 
import copy


def Gen_one_case( case_id, max_prim_in, max_op_cnt ):

    prim_in_cnt  = random.randint(5, max_prim_in)
    op_cnt = random.randint(prim_in_cnt * 2, max(max_op_cnt, prim_in_cnt * 4))

    ### format of an operation
    # [i, type, prec]
    # i is the node id
    # type is the operation type: -2: prim_in, -1: prim_out, 1: add, 2: mul
    # prec is the data precision, from 2 to 16-bit
    # do is the output degree

    all_ops = []
    all_ops.append( [-1, -1, -1, -1] ) # place holder

    ### generate primary inputs
    prim_ins = []
    for i in range(1, prim_in_cnt + 1):
        p_in = i
        prec = random.randint(2, 16)
        prim_ins.append( [i, -2, prec, 0] )
        all_ops.append( [i, -2, prec, 0] )

    ### generate intermediate operations
    inter_ops = []
    for i in range(prim_in_cnt + 1, prim_in_cnt + op_cnt + 1):
        prec = -1
        # 1 stands for addition, 2 stands for multiplication
        op_type = int(round(random.uniform(1.3, 2.3)))
        inter_ops.append( [i, op_type, prec, 0] )
        all_ops.append( [i, op_type, prec, 0] )

    ### generate edges
    available_ops = copy.deepcopy(prim_ins)
    unsigned_ops = copy.deepcopy(inter_ops)
    all_edges = []
    idx = 0
    while unsigned_ops:

        # the unsigned intermediete operator
        op = unsigned_ops.pop(0)
        opr1 = sample(available_ops[idx :], 2)[0]
        opr2 = sample(available_ops[idx :], 2)[1]

        # out-degree += 1
        all_ops[opr1[0]][3] = all_ops[opr1[0]][3] + 1
        all_ops[opr2[0]][3] = all_ops[opr2[0]][3] + 1

        # infer the data precision with randomness
        opr1_prec = opr1[2]
        opr2_prec = opr2[2]
        op_prec = random.randint( max(2, (opr1_prec + opr2_prec)/4 ), min(opr1_prec + opr2_prec, 16) )
        op[2] = all_ops[op[0]][2] = op_prec

        # add two in-edges for the operator
        available_ops.append(op)
        all_edges.append( [all_ops[opr1[0]], all_ops[op[0]]] )
        all_edges.append( [all_ops[opr2[0]], all_ops[op[0]]] )

        # age the available_ops
        idx = idx + 1

    ### generate primary outputs and assign outputs
    ### assign those intermediate operations to primary outputs if their out-degree is zero
    prim_outs = []
    i = prim_in_cnt + op_cnt
    for op in all_ops[1:]:
        if op[3] > 0 or op[1] == -2:
            continue

        i = i + 1
        # assuming all outputs are 16-bit
        prec = 16

        p_out = [i, -1, prec, 0]
        prim_outs.append(p_out)
        all_edges.append( [op, p_out] )

    all_ops = all_ops + prim_outs
    prim_out_cnt = len(prim_outs)

#    print("# of primary inputs: " + str(prim_in_cnt))
#    print("# of intermediate operations: " + str(op_cnt))
#    print("# of primary outputs: " + str(prim_out_cnt))

#    print("\nprim_ins")
#    print(all_ops[1: prim_in_cnt+1])

#    print("\ninter_ops")
#    print(all_ops[prim_in_cnt+1: prim_in_cnt+op_cnt+1])

#    print("\nprim_outs")
#    print(all_ops[prim_in_cnt+op_cnt+1: prim_in_cnt+op_cnt+prim_out_cnt+1])

#    print("\nedges")
#    for e in all_edges:
#        print(e)



    ### Generate the graph
    f_graph = open("DFG_case_" + str(case_id) + '.txt', "w")

    io_dic = {-2: 'in', -1: 'o', 1: 'm', 2: 'm'}
    tp_dic = {1: '+', 2: '*'}

    # Primary Inputs:
#    print("# Primary Inputs:")
    f_graph.write("# Primary Inputs:\n")
    for op in all_ops[1: prim_in_cnt+1]:
        op_name = 'in' + str(op[0])
        op_prec = 'INT' + str(op[2])
#        print("%s %s" % (op_name, op_prec))
        f_graph.write("%s %s\n" % (op_name, op_prec))

    # Intermediate Operations:
#    print("\n\n# Intermediate Operations:")
    f_graph.write("\n\n# Intermediate Operations:\n")
    for op in all_ops[prim_in_cnt+1: prim_in_cnt+op_cnt+1]:
        op_name = 'm' + str(op[0])
        op_prec = 'INT' + str(op[2])
        op_type = tp_dic[op[1]]

#        print("%s %s %s" % (op_name, op_type, op_prec))
        f_graph.write("%s %s %s\n" % (op_name, op_type, op_prec))

    # Edges:
#    print("\n\n# Edges:")
    f_graph.write("\n\n# Edges:\n")
    for e in all_edges:
        op1 = e[0]
        op2 = e[1]
        pre1 = io_dic[op1[1]]
        pre2 = io_dic[op2[1]]

#        print("%s%d %s%d" % (pre1, op1[0], pre2, op2[0]))
        f_graph.write("%s%d %s%d\n" % (pre1, op1[0], pre2, op2[0]))


#    print("\n\n# Primary Outputs:")
    f_graph.write("\n\n# Primary Outputs:\n")
    for op in all_ops[prim_in_cnt+op_cnt+1: prim_in_cnt+op_cnt+prim_out_cnt+1]:
#        print("o" + str(op[0]))
        f_graph.write("o" + str(op[0]) + "\n")

    f_graph.close()

    #### Generate HLS code

    file_head = """

#include <stdio.h>
#include "ap_fixed.h"

void case_%d(
    ap_int<16> in_data[%d],
    ap_int<16> out_data[%d]
)
{

#pragma HLS array_partition variable=in_data complete
#pragma HLS array_partition variable=out_data complete

    """ % (case_id, prim_in_cnt, prim_out_cnt)

    file_tail = """
}
    """

    ### write inputs
    lines = """

"""
    for i in range(1, prim_in_cnt + 1):
        lines += "ap_int<%d> in%d;\n"                     % ( all_ops[i][2], all_ops[i][0] )
        lines += "in%d.range(%d, 0) = in_data[%d].range(%d, 0);\n"                     % ( all_ops[i][0], all_ops[i][2]-1, i-1, all_ops[i][2]-1 )
    lines += "\n"

    ### write intermediate operators
    for i in range(prim_in_cnt+1, prim_in_cnt+op_cnt+1):
        lines += "ap_int<%d> m%d;\n" % (all_ops[i][2], all_ops[i][0])
    lines += "\n"

    ### write operations
    op_dic = {}
    for e in all_edges:
        u = e[0]
        v = e[1]

        if v[0] not in op_dic.keys():
            op_dic[v[0]] = u[0]
            continue

        op1 = op_dic[v[0]]
        op2 = u[0]
        pre1 = io_dic[all_ops[op1][1]]
        pre2 = io_dic[all_ops[op2][1]]
        op_type = tp_dic[v[1]]

        line = "m%d = %s%d %s %s%d;\n" % (v[0], pre1, op1, op_type, pre2, op2)
        lines += line
    lines += "\n"

    ### write outputs
    for i in range(prim_in_cnt+op_cnt+1, prim_in_cnt+op_cnt+prim_out_cnt+1):
        op = op_dic[all_ops[i][0]]
        lines += "out_data[%d] = m%d;\n" % (i-(prim_in_cnt+op_cnt+1) , op)
    lines += "\n"

    content = file_head + lines + file_tail
#    print(content)

    f_HLS = open("case_" + str(case_id) + '.cc', "w")
    f_HLS.write(content)
    f_HLS.close()

    # Generate HLS directive file

    f_directive = open("directive.tcl", "w")

    content = ""
    for i in range(prim_in_cnt+1, prim_in_cnt+op_cnt+1):
        content += "set_directive_resource -core Mul_LUT \"case_%d\" m%d\n" % (case_id, i)
    content += "\n"

    f_directive.write(content)
    f_directive.close()

    f_script = open("script.tcl", "w")
    content = """

open_project project_
set_top case_
add_files PATH/case_.cc
open_solution "solution_"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./directive.tcl"
csynth_design
export_design -evaluate verilog -format ip_catalog
exit

"""

    f_script.write(content)
    f_script.close()

