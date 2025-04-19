#!/usr/bin/bash
###
#
# Estruturas condicionais - FUNÇÃO - function
clear

function1 () {
	echo "Diretório $DIRECT existe"
	}

function2 () {
	echo "Diretório $DIRECT não existe"
	}

echo -n "Digite um diretório: "
read DIRECT
echo

if [ -d $DIRECT ] ; then
	function1
else
	function2
fi


###

