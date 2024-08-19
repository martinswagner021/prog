import socket
server = f'{socket.gethostname()}.local' # Generic form

import sys
EXERCICIO = int(sys.argv[1])

import pymongo
import json

client = pymongo.MongoClient(f'mongodb://{server}:27017/')

db = client['BD']

colObra = db['Obra']
colSalao = db['Salao']


# 1)
if EXERCICIO==1:
    res = colObra.find({"autoria.nome" : "Michelangelo"})
    for i in res:
        print(i['titulo'], i['salao_REF'])

# 2)
if EXERCICIO==2:
    res = colObra.find({"$and": [{"autoria.nacionalidade" : "Italiana"}, {"escultura": {"$ne": {}}}]})
    for i in res:
        print(i['titulo'])

# 3)
if EXERCICIO==3:
    colSalao.insert_one({
        "ID_numero": 5,
        "andar": 3,
        "horarios": [
            {
            "horario": "08:00 - 13:00"
            }
        ]
    })

# 4)
if EXERCICIO==4:
    colSalao.delete_many({"andar": 2})

# 5)
if EXERCICIO==5:
    colSalao.update_many({"andar": 1}, {
        "$set": {
            "horarios": [
                {"horario": "8:00 - 13:00"},
                {"horario": "14:00 - 18:00"}
            ]
        }
    })