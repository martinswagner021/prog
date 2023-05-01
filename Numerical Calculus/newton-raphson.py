"""
Calcula o zero de uma função pelo Método de Newton-Raphson
"""

from sympy import *
x = Symbol("x")


def MetNewtonRaphson(expr, x0, E):
    """
    Calcula o zero de uma função pelo Método de Newton-Raphson
    """
    # expr é a expressão da função cujo zero será calculado.
    # x0 é o valor inicial.
    # E é o erro tolerado no critério de parada.
    f = Lambda(x, expr)
    df = Lambda(x, diff(f(x), x))

    # Guarda o valor inicial.
    x_n_menos_1 = float(x0)

    # Inicializa o contador de interações.
    n = 0

    # Entra no processo iterativo.
    while 1:

        # Atualiza o contador de iterações.
        n = n + 1

        # Teste de admissibilidade.
        if df(x_n_menos_1) == 0:
            print("O método não converge. Reinicie com outro valor inicial.")
            break

        # Calcula o valor aproximado do zero da função
        x_n = x_n_menos_1 - f(x_n_menos_1)/df(x_n_menos_1)

        # Teste da solução exata.
        if f(x_n) == 0:
            print(f"O valor exato do zero da função dada é x_[{n}] = {x_n}")
            break

        # Calcula os erros associados ao valor aproximado do zero da função.
        Er = abs(f(x_n))
        Ex = abs(x_n - x_n_menos_1)

        # Guarda o valor aproximado da atual iteração.
        x_n_menos_1 = x_n

        # Imprime os resultados parciais de cada iteraçao.
        print(f"Iteracao {n} | x_{n} =  {x_n} | Er = {Er} | Ex = {Ex}")

        # Teste de parada.
        if Er <= E and Ex <= E:
            break

    # Retorna a solução aproximada que satisfaz o critério de parada.
    print(f"A solução aproximada é x_{n} = {x_n}.")
    return x_n

res = MetNewtonRaphson(
    (5300*(x**10))-((x**9+x**8+x**7+x**6+x**5+x**4+x**3+x**2+x+1)*570),
    1,
    10**-5
)

print(f"tm = {res}-1 = {res-1}")