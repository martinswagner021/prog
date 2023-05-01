
n = int(input())

def fatorial(n):
    i = n-1
    while(i>0):
        n = n*i
        i=i-1

    return n

normais = int(n/5)
print(int(normais))
    
print(fatorial(n))