#!/usr/bin/bash
###
#  
#
# Estruturas condicionais - Laços repetitivos - FOR
clear
nohup sleep 10 & 
sleep 2
for ((X=1;X<=15;X++)); do
        ps -ef | grep 'sleep' 
	ps -ef | grep 'sleep' | wc -l
	sleep 1
	clear
done
