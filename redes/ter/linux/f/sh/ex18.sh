#!/usr/bin/bash
###
#  
# Script 32
# 
# Estruturas condicionais - while - LOOPs
clear

CONT=1

echo -ne "Quantas vezes devo executar o LOOP? "
read -n 1 VAL

clear

echo "Você escolheu $VAL"

sleep 2

clear

while [ "$CONT" -le "$VAL" ] ; do
	echo "Executando pela $CONT vez"
	sleep 1
	clear
	CONT=$(expr $CONT + 1)
done

echo "TCHAU"
sleep 2
clear
