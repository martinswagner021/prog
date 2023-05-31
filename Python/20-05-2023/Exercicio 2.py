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
        for topic in row:
            temp[header[i]] = topic
            i += 1
        scopus_data.append(temp)
        continue

with open('scopus_output.json', 'w') as scopus_output:
    json.dump(scopus_data, scopus_output, indent=3, ensure_ascii=False)