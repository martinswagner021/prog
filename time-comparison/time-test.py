import time
start = time.time()
N = 100000
x = [i for i in range(N)]
print(x)

for i in range(N):
    max = 0
    for j in range(i,N):
        if x[j] > x[max]:
            max = j
    aux = x[i]
    x[i] = x[max]
    x[max] = aux
end = time.time()

print(x)

print(f'time taken: {(end-start)}')