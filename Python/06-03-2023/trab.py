# Trabalho grande
# Listar todos os diretorios em uma dict e salvar em json
# Autor: Wagner Martins

import os
import json

w = os.walk(".", topdown=False)

diretorio = {}

for i in w:
    temp = {}
    temp["nome_do_diretorio"] = i[0]
    temp["arquivos"] = i[2]
    temp["diretorios"] = i[1]
    print(i)

with open("saida-diretorios.json", "w") as saida_json:
    json.dump(diretorio, saida_json, indent=3)