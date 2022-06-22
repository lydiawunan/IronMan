# IronMan

**Related Papers**
* [GLSVLSI'21] [IronMan: GNN-ass<u>i</u>sted Design Space Explo<u>r</u>ati<u>o</u>n in High-Level Sy<u>n</u>thesis via Reinforce<u>m</u>ent Le<u>a</u>r<u>n</u>ing](https://dl.acm.org/doi/abs/10.1145/3453688.3461495)
* [TCAD'22] IronMan-Pro: Multi-objective Des<u>i</u>gn Space Explo<u>r</u>ati<u>on</u> in HLS via Reinforce<u>m</u>ent Le<u>a</u>r<u>n</u>ing and Gra<u>p</u>h Neu<u>r</u>al Network based M<u>o</u>deling (Accepted, to appear)


<figure>
<img src=image/fig_overall4.png alt="Trulli" style="width:100%">
<figcaption align = "center">The proposed <u>IronMan-Pro</u> is a learning-based framework composed of <u>CT</u>, <u>GPP</u>, and <u>RLMD</u>. During training, <u>IronMan-Pro</u> takes HLS C/C++ code and IRs as inputs and the actual RTL performance (e.g., resource and timing) as the ground truth to train GPP and RLMD. During inference, the well-trained GPP provides graph embeddings and performance predictions to RLMD; the trained RLMD either finds optimized directives that satisfy user-specified design constraints such as available resources, or generates Pareto-solutions with various trade-offs between different resource types.</figcaption>
</figure>






## Prerequisites
* TensorFlow 3.6.x
* Stellargraph >= 1.2.0
* Vitis HLS
* Vivado

## Dataset Generation
* [Synthetic DFGs generation](https://github.com/lydiawunan/IronMan/tree/main/synthetic_case_generation/readme.md).
* After DFGs are generated, move them to [DATASET](https://github.com/lydiawunan/IronMan/tree/main/DATASET).
* [data_preprocess.py](https://github.com/lydiawunan/IronMan/tree/main/data_preprocess.py) and [generate_graph_datasets.py](https://github.com/lydiawunan/IronMan/tree/main/generate_graph_datasets.py) produce the necessary dataset files for GPP training.

## GPP
* Three GNN-based models to predict DSP, LUT, and critical path (CP) timing.
* After GPP is well trained, move the proxy models and the embedding models to [RLMD](https://github.com/lydiawunan/IronMan/tree/main/RLMD).


## RLMD
* Two RL methods are included in RLMD: actor critic, and policy gradient.
* [hls_env.py](https://github.com/lydiawunan/IronMan/tree/main/RLMD/hls_env.py): the environment.
* [target_tuples.py](https://github.com/lydiawunan/IronMan/tree/main/RLMD/target_tuples.py): shuffle the tuples for RLMD training.

## Meta-heuristics
* We include simulated annealing (SA), genetic algorithm (GA), particle swarm optimization (PSO), and ant colony optimization (ACO).
* Note that these meta-heuristics also need the help of GPP.

## Data Post-processing
* [data_postprocess.ipynb](https://github.com/lydiawunan/IronMan/tree/main/data_postprocess.ipynb): convert generated solutions to json files.
* [Get_Perf.py](https://github.com/lydiawunan/IronMan/tree/main/Get_Perf.py): invoke Vitis HLS and Vivado to get the post-implementation resource usage and timing, given the json files (solutions) and cc files (designs in C++).

## Contact
- If there is any question, please drop an email to nanwu@ucsb.edu
- If you find IronMan useful, please cite our paper:
   ```
   @inproceedings{wu2021ironman,
    title={Ironman: GNN-assisted Design Space Exploration in High-Level Synthesis via Reinforcement Learning},
    author={Wu, Nan and Xie, Yuan and Hao, Cong},
    booktitle={Proceedings of the 2021 on Great Lakes Symposium on VLSI},
    pages={39--44},
    year={2021},
    organization={IEEE}
    }
   ```
