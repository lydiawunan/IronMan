
import random
import itertools
from string import Template
import subprocess
import json
import math
import re


def get_LUT_op_list(directives):
	LUT_op_list = []
	for direct in directives:
		if direct.startswith('#'):
			continue
		res = map(int, re.findall(r'\d+', direct))
		if len(res) == 2:
			LUT_op_list.append(res[1])
	return LUT_op_list


def run_one_case(case_id, path, samp_num = 100, sol = 1):
	## Get script

	print("Running case %d" % case_id)

	f_script = open(path + 'script.tcl', 'r')
	script_template = f_script.read()
	f_script.close()

	f_directive = open(path + 'directive.tcl', 'r')
	directive_all = f_directive.read()
	f_directive.close()

	directive_list = []
	for line in directive_all.splitlines():
		directive_list.append(line)

	all_lists = []
	## THIS IS THE VIVADO HLS BASELINE
	if sol == 1:
		all_lists.append([])

	for i in range(1, samp_num):
		direct_list_sampled = []
		for directive in directive_list:
			ri = random.uniform(0, i%17+4)
			if ri <= 3:
				directive = "# " + directive
			direct_list_sampled.append(directive)
		all_lists.append(direct_list_sampled)

	print("Generated %d combinations of directives" % len(all_lists))

	json_file = path + "case_" + str(case_id) + "_all_data.json"
	if sol == 1:
		all_solutions = {}
		f_json = open(json_file, "w")
		json.dump(all_solutions, f_json)
		f_json.close()

	for directives in all_lists:
		print("Generating vivado HLS directive files for solution_%d" % sol)
		f_direct_name = "./directive_tmp.tcl"
		f_direct = open(f_direct_name, "w")
		for ele in directives:
			f_direct.write(ele + "\n")
		f_direct.close()
		f_script_name = "./script_tmp.tcl"
		f_script = open(f_script_name, "w")
		#script_content = script_template.substitute(sol = str(sol), f_directive = f_direct_name)
		script_content = script_template.replace('solution_', 'solution_tmp').replace('directive', 'directive_tmp').replace('case_', 'case_' + str(case_id))
		script_content = script_content.replace('PATH', path).replace('project_', 'project_tmp')
		f_script.write(script_content)
		f_script.close()

		print("Running Vivado HLS for solution_%d" % sol)
		subprocess.call(['vivado_hls', '-f', f_script_name])

		rpt_name = 'project_tmp/solution_tmp/impl/report/verilog/case_%d_export.rpt' % (case_id)
		f_rpt = open(rpt_name, 'r')
		SLICE = LUT = FF = DSP = CP = 0
		for line in f_rpt.readlines():
	        	res = [i for i in line.split() if i.isdigit()]
		        if line.startswith('SLICE'):
	        	        SLICE = int(res[0])
		        elif line.startswith('LUT'):
	        	        LUT = int(res[0])
		        elif line.startswith('FF'):
	        	        FF = int(res[0])
		        elif line.startswith('DSP'):
	        	        DSP = int(res[0])
		        elif line.startswith('CP achieved'):
	        	        res = [i for i in line.split()]
	                	CP = float(res[2])
		print(SLICE, LUT, FF, DSP, CP)

		f_json = open(json_file, "r")
		all_solutions = json.load(f_json)
		f_json.close()

		all_solutions["solution_" + str(sol)] = {}
		sol_tb = all_solutions["solution_" + str(sol)]
		sol_tb['directives'] = directives
		sol_tb['LUT_op'] = get_LUT_op_list(directives)
		sol_tb['SLICE'] = int(SLICE)
		sol_tb['LUT'] = int(LUT)
		sol_tb['FF'] = int(FF)
		sol_tb['DSP'] = int(DSP)
		sol_tb['CP'] = float(CP)

		f_json = open(json_file, "w")
		json.dump(all_solutions, f_json)
		f_json.close()

		sol = sol + 1
		

def main():
	run_one_case(3, "/HLS_ML/data_collect/HLS/case_3/", samp_num = 100)

if __name__ == "__main__":
    main()

