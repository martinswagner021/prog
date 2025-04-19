#!/usr/bin/bash
###
#  
#
# Estruturas condicionais - while - LOOPs
clear
X=1
until [ "$X" -gt 10 ] ; do
	echo "LOOP até 10. Contando: $X"
	sleep 1
	let X=X+1
done
