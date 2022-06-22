import json
import subprocess
import time
from os import path

numbers = [str(i) for i in range(1,9)] + [str(i) for i in range(11, 17)] + [str(i) for i in range(18, 24)]
case_names = ['case_' + number for number in numbers]
for case_name in case_names:

    for method in ['ga']:

        Method_file = open(case_name + '_%s_solution.json' % method, 'r')
        Method_sol = json.load(Method_file)
        Method_directive = []
        
        script_name = 'script.tcl'
        script_content = """
open_project project_tmp
set_top %s
add_files %s.cc
open_solution "solution_tmp"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./directive.tcl"
csynth_design
export_design -evaluate verilog -format ip_catalog
exit
            """ % (case_name, 'cc/'+case_name)
        f = open(script_name, 'w')
        f.write(script_content)
        f.close()

	    
        for ele in Method_sol:
            
            print("Solution ID: " + ele)
            sol = Method_sol[ele]['solution']
            print(sol)
            f = open('directive.tcl', 'w')
            for m in sol:
                directive = "set_directive_resource -core Mul_LUT \"%s\" m%s\n" % (case_name, str(m))
                f.write(directive)
            f.close()

            
            p = subprocess.Popen(['rm', '-rf', 'project_tmp'], stderr=subprocess.STDOUT)
            p = subprocess.Popen(['vitis_hls', '-f', script_name], stderr=subprocess.STDOUT)
            t = 0
            while( t < 2000 ):
                time.sleep(5)
                if p.poll() != None:
                    break
                t = t + 1
                
            if p.poll() == None:
                p.kill()

            rpt_name = 'project_tmp/solution_tmp/impl/report/verilog/%s_export.rpt' % (case_name)
            if not path.exists(rpt_name):
                continue
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
                    CP = float(res[3])
            print(SLICE, LUT, FF, DSP, CP)

            json_name = case_name + '_%s_solution_real.json' % method
            if not path.exists(json_name):
                Method_sol_real = {}
            else:
                Method_file_real = open(json_name, 'r')
                Method_sol_real = json.load(Method_file_real)
                Method_file_real.close()

            Method_sol_real[ele] = {}
            Method_sol_real[ele]['SLICE'] = SLICE
            Method_sol_real[ele]['LUT'] = LUT
            Method_sol_real[ele]['FF'] = FF
            Method_sol_real[ele]['DSP'] = DSP
            Method_sol_real[ele]['CP'] = CP
            
            Method_file_real = open(case_name + '_%s_solution_real.json' % method, 'w')
            json.dump(Method_sol_real, Method_file_real)
            Method_file_real.close()
