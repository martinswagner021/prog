#!/usr/bin/bash
###
#  
# Estruturas condicionais - SELETOR
clear
while true ; do
clear
	echo "-._______________________.-"
	echo "-                         -"
	echo "-  1) Pingar localhost    -"
	echo "-  2) Quem está logado    -"
	echo "-  3) IP da ETH0          -"
	echo "-  4) Memória             -"
	echo "-  5) Espaço em disco     -"
	echo "-  x) sair                -"
	echo "-._______________________.-"
	echo
	echo "-  Opção"

	read -n 1 RESP
	
	case $RESP in
		1) echo ; ping -c 5 localhost ;;
		2) echo ; who ; sleep 5 ;;
		3) echo ; ifconfig eth0 ; sleep 5 ;;
		4) echo ; free -m ; sleep 5 ;;
		5) echo ; df -h ; sleep 5 ;;
		x) break ;;
		*) echo ; echo "Opção inválida!" ;  sleep 3 ;;
	esac
done
echo
###

