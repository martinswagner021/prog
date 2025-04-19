#!/usr/bin/bash
###
#  
# 
# Estruturas condicionais - while - LOOPs
clear

while true ; do 
	echo -ne "Deseja sair do script? [S] ou [N]:"
	read -n 1 KEY
	echo
	if [ "$KEY" = "n" ] || [  "$KEY" = "N" ] ; then
		echo "OK! Vou continuar no script"
		sleep 2
		clear
		continue
	fi
	if [ "$KEY" = "s" ] || [ "$KEY" = "S" ] ; then
		echo "Saindo do script"
		break 
	fi
done

cal

# Se comentar o "continue" e adicionar um comando 
# antes do "done", ele será executado
