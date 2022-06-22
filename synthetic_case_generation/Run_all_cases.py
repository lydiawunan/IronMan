from Run_one_case import *


all_cases = 10
for case in range(1, 1 + all_cases):
	path = "/HLS/case_" + str(case) + "/"
	# solution_1 is the default HLS solution
	run_one_case(case, path, samp_num = 100, sol = 1)
