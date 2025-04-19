import json

with open("entrada.json", "r") as arq:
    dados = json.load(arq)

dados = dados[1]

with open("saida.json", "w") as arq:
    json.dump(dados, arq, indent=3, ensure_ascii=False) # ensure_ascii=False habilita as acentuacoes