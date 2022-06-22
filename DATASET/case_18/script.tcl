

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

