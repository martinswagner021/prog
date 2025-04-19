#!/usr/bin/bash
###
#  
# Estruturas condicionais - SELETOR
clear

DATA=`date +%w`
case $DATA in
	0) DIA="Hoje é Domingo" ;;
	1) DIA="Hoje é Segunda" ;;
	2) DIA="Hoje é Terça" ;;
	3) DIA="Hoje é Quarta" ;;
	4) DIA="Hoje é Quinta" ;;
	5) DIA="Hoje é Sexta" ;;
	6) DIA="Hoje é Sábado" ;;
esac
echo $DIA
