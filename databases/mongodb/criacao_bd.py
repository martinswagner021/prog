import socket
server = f'{socket.gethostname()}.local' # Generic form

import pymongo
import json

client = pymongo.MongoClient(f'mongodb://{server}:27017/')

db = client['BD']

colObra = db['Obra']
colSalao = db['Salao']

colObra.delete_many({})
colSalao.delete_many({})

with open("dados.json") as data:
    mydata = json.load(data)

colObra.insert_many(mydata['obras'])
colSalao.insert_many(mydata['saloes'])