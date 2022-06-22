1. Run Gen_all_cases.py to generate random DFG graphs, each in its folder "case_%d"
   - Outputs include: a DFG for each case, an HLS .cc file, a script.tcl, and a directive.tcl
   - The case ID starts from 1, which can be changed in Gen_all_cases.py
   - To change the size of the DFG: "max_op_cnt" and "prim_in_cnt" in Gen_all_cases.py
   - To change the number of directive combinations: "samp_num" in Run_all_cases.py

2. Run Run_all_cases.py to run all DFGs using Vivado, to abtain an actual and accurate LUT and DSP utilization

3. The collected data are stored in "case_%d_all_data.json" for "case_%d" using a json file format.
   Data format in the .json file:
   - table['solution_1'] contains the default solution of Vivado HLS, while others are randomly sampled.
   - The entries in table['solution_%d'] include:
     + Resource utilization: table['solution_%d']['DSP'], table['solution_%d']['LUT'], table['solution_%d']['SLICE']
     + The current HLS directives: table['solution_%d']['directives'] and table['solution_%d']['LUT_op']
       - The 'directives' entry stores the content of a complete directive.tcl file
       - The 'LUT_op' entry stores the list of the operation IDs that are specified as LUT using directives
