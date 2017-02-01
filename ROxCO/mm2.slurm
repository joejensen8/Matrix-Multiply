#!/bin/bash
#SBATCH -n 1
#SBATCH -p normal
#SBATCH -o mm2.txt
#SBATCH -t 01:10:00
echo Running Slurm Script for mm2
./mm2.out 

