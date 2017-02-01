#!/bin/bash
#SBATCH -n 1
#SBATCH -p normal
#SBATCH -o mm1.txt
#SBATCH -t 01:10:00
echo Running Slurm Script for mm1
./mm1.out 

