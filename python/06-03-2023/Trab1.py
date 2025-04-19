# Trabalho grande
# Listar todos os diretorios em uma dict e salvar em json
# Autor: Wagner Martins

import os
import json

usr_directory = input("Digite o nome do diretorio: ")


def get_dic(usr_dir):
    w = os.walk(usr_dir)
    diretorio = {}

    for dirpath, _, files in w:
        aux = diretorio
        path = dirpath.split(os.sep)
        for i in path:
            aux = aux.setdefault("diretorios", {}).setdefault(i, {"nome_do_diretorio": i,"arquivos": [], "diretorios": {}})
        aux["arquivos"].extend(files)
    return diretorio["diretorios"]

with open("saida-diretorios.json", "w") as saida_json:
    json.dump(get_dic(usr_directory), saida_json, indent=3)