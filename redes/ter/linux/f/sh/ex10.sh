#!/usr/bin/bash
# Interagindo com o usuário – condicinando digitação
#
clear 
echo -ne "Digite uma letra: [S] ou [N]: "
read -n 1 KEY
echo
clear
echo  "A letra digitada é: $KEY"
