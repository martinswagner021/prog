'''
Exercicio 1: Faca um programa que leia um arquivo.txt contendo o nome de uma pessoa em uma linha e as notas na proxima e escreva o nome das pessoas e as medias na mesma linha em um arquivo.txt
'''

mfile = open("entrada.txt", "r")

t = mfile.read()

t = t.replace(',', '.')

t = t.split('\n')

medias = {}
for i in range(0, t.__len__(), 2):
    nome = t[i]
    med = t[i+1]
    med = list(map(float, med.split(' ')))
    med = sum(med)/med.__len__()

    medias[nome] = med

saida = open("saida.txt", "w")
for i in medias:
    saida.write(f"Estudante: {i} | {round(medias[i], 2)}\n")


saida.close()
mfile.close()