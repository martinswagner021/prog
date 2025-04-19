n = int(input())

for i in range(n):
    linha = input().split(' ')
    instante = int(linha[0])
    tempo = linha[1].split('T')
    tempo = int(tempo[0])
    if(tempo==1):
        if(instante>45):
            print(f'{45}+{instante%45}')
        else:
            print(instante)
    else:
        if(instante>45):
            print(f'{90}+{instante%45}')
        else:
            print(instante+45)