A=[]
B=[]
C=[]

def getmatrix(X):
    print("Insert how many lines are there: ")
    lines = int(input())
    print("Insert how many columns are there: ")
    columns = int(input())
    for i in range(lines):
        temp=[]
        for j in range(columns):
            print(f'Insert element [{i}][{j}]: ')
            temp.append(int(input()))
        X.append(temp)

print("Inserting data to matrix A...")
getmatrix(A)
print("Inserting data to matrix B...")
getmatrix(B)

# SUPUNHETAMOS QUE SEJA MATRIZ QUADRADA
for i in range(len(A)):
  temptemp=[]
  for k in range(len(A)):
    temp=[]
    for j in range(len(A)):
      soma=[]
      soma.append(A[i][j]*B[j][k])
      temp.append(sum(soma))
    temptemp.append(sum(temp))
  C.append(temptemp)

for i in C:
    print(i)
    