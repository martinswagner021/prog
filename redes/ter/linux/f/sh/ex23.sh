#!/usr/bin/bash
###
#  
#
# Estruturas condicionais - SELETOR
clear

echo -ne "Pressione S ou N: "
read -n 1 KEY
echo

case $KEY in
	s|S)
	echo "Você digitou $KEY"
	;;
	n|N)
	echo "Você digitou $KEY"
	;;
	*)
	echo "Distraído. Eu mandei teclar S ou N"
	;;
esac
	

