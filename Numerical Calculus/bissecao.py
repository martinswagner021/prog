
def MetBisseccao(f, a, b, E):
    """ Método da Bissecção para o cálculo do zero de uma função contínua f.
     Use MetBisseccao(lambda: <expr>, a, b, E) onde:
     <expr> é a expressão matemática que define a função f(x)
     a é o limite inferior do intervalo de busca inicial.
     b é o limite superior do intervalo de busca inicial.
     E é o erro tolerado.
    """

    #
    # A função f tem que ser entrada na forma  lambda x: <expressão envolvendo x>

    if f(a) * f(b) > 0:
        print("Não há garantia da existência de um zero no intervalo dado. Escolha outro intervalo")
        return 
    else:
        n = 1
        x_n = (a + b)/2
        Er = abs(f(x_n))
        print(f"Iteracao {n} | intervalo de busca [{a} , {b}] | x_{n} =  {x_n} | Er = {Er} | Ex = N/A")
        while True:
            if f(x_n) == 0:
                print(f"A solução exata é " )
                return x_n
            n += 1
            x_n_menos_1 = x_n
            if f(a) * f(x_n) < 0:
                b = x_n
            else:
                a = x_n
            x_n = (a + b)/2

            Er = abs(f(x_n))
            Ex = abs(x_n - x_n_menos_1) 

            print("-----------------")
            print(f"Iteracao {n} | intervalo de busca [{a} , {b}] | x_{n} =  {x_n} | Er = {Er} | Ex = {Ex}")

            if (Er <= E) and (Ex <= E):
                break
    return 

MetBisseccao(lambda x: 4*x**5+5*x**2+6*x+3, -3, 2, 10**-8)