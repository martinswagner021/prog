# Arquivo teste2.json no classroom
import json

with open("entrada.json", "r") as arq:
    dados = json.load(arq)

for i in dados:
    print(f"Turma: {i['Curso']}")
    for j in i['Alunos']:
        print(j['nome'])