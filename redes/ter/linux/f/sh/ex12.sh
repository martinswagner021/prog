#!/usr/bin/bash
###
#  
# Teste com ARRAYs
clear

echo -n "Digite as 4 notas do aluno separadas por espaços: "
read NOTAS

MEDIA=($NOTAS)

echo "As notas foram: ${MEDIA[@]}
1 bimestre: ${MEDIA[0]}
2 bimestre: ${MEDIA[1]}
3 bimestre: ${MEDIA[2]}
4 bimestre: ${MEDIA[3]}"
echo
SOMA_NOTAS="$((${MEDIA[0]} + ${MEDIA[1]} + ${MEDIA[2]} + ${MEDIA[3]}))"
echo "As notas somaram: $SOMA_NOTAS"

echo -n "Calculando a média aluno: $((${SOMA_NOTAS} / 4))"
echo
