n = int(input())

def comp(i):
    return len(i)

for i in range(n):
    linha = input()
    linha = linha.split(' ')
    linha.sort(reverse=True, key=comp)
    for j in linha:
        if(j!=linha[0]):
            print(' ', end='')
        print(j, end='')

    print()

