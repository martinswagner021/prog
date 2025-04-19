#!/usr/bin/bash
###
#
# Estruturas condicionais - IF
clear

echo -ne "Digite uma letra [s] ou [n]:" 
read -n 1 KEY

echo

if [ "$KEY" = "s" ] ; then
	echo "Você digitou $KEY"
elif [ "$KEY" = "n" ] ; then
	echo "Você digitou $KEY"
else
	echo "Você digitou $KEY. Não foi o que eu pedi!"
fi
