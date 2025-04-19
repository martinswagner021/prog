#!/usr/bin/bash
# Interagindo com o usuário – calculando tamanho da variável
#
echo -n "Por favor, digite seu nome: "
read NOME
echo
echo "Seu nome é: $NOME"
echo "Seu nome possui `expr length $NOME` letras"
#FIM
