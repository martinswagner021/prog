#!/usr/bin/bash
###
#
# Estruturas condicionais - IF
clear

echo -ne "Digite uma letra [S] ou [N]:"
read -n 1 KEY

echo

if [ "$KEY" = "s" ] || [ "$KEY" = "S" ] ; then
	echo "Você digitou $KEY"
elif [ "$KEY" = "n" ] || [ "$KEY" = "N" ] ; then
	echo "Você digitou $KEY"
else
	echo "Você digitou $KEY. Não foi o que eu pedi!"
fi
