'''
Exercicio 2: Faca um programa que leia o arquivo "scopus.csv" no drive, o qual representa publicacoes da area de ciencia da computacao em revistas cientificas. Imprima na tela o nome dos autores "Authors" das publicacoes com mais de 20 citacoes "Cited by"
'''
import csv

mfile = open("scopus.csv", "r")

r = csv.reader(mfile)

for row in r:
    if(row[11] == "Cited by"):
        continue
    if(row[11] == ""):
        continue
    if(int(row[11]) > 100):
        print(f"Autores: {row[0]}")