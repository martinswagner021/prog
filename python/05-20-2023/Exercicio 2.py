'''
Exercicio 2
'''
import csv
import json

mfile = open("scopus.csv", "r")

r = csv.reader(mfile)

scopus_data = []

header = []

for row in r:
    if(row[11] == "Cited by"):
        header += row
        continue
    if(row[11] == ""):
        continue
    if(int(row[11]) > 20):
        i = 0
        temp = {}
        temp.setdefault("Authors", row[0])
        temp.setdefault("Cited by", row[11])
        scopus_data.append(temp)
        continue

with open('scopus_output.json', 'w') as scopus_output:
    json.dump(scopus_data, scopus_output, indent=3, ensure_ascii=False)