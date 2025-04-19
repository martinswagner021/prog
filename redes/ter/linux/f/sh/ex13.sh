#!/usr/bin/bash
###
#  
#
# Estruturas condicionais - IF
clear

ARQ=arquivo_teste
if [ -e $ARQ ] ; then
	echo "Arquivo existe!"
	echo "Olha ele aí"
	ls -l $ARQ
else
	echo "Arquivo não existe! Criando-o!!!"
	touch $ARQ
fi
