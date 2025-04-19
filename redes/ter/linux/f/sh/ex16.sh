#!/usr/bin/bash
###
#
# Estruturas condicionais - IF
# Lidando com parâmetros externos
#clear

HELP="Este programa exibe a data local

Uso: ./.ex16.sh [opções]

Opções:

-h	Exibe o help do script
-d	Exibe somente o dia da semana
-D	Exibe o dia do mês
"

if [ "$1" = "-h" ] ; then
	echo "$HELP"
	exit 0
elif [ "$1" = "-d" ] ; then
	echo "Hoje é `date +%A`"
	exit 0
elif [ "$1" = "-D" ] ; then
	echo "Hoje é o dia `date +%d` do mês"
	exit 0
fi

echo "Hoje é `date +%A`, `date +%d` de `date +%B` de `date +%Y`"

