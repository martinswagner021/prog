-- Define a funcao f(x)
local function f(x)
    return x^2 - 2
end

-- Define o intervalo [a, b]
local a = -2
local b = 0

-- Define o erro toleravel para a aproximacao
local tol = 1e-6

-- Numero de iteracoes maxima desejada
local max_iter = 1000

local function bisection_method(f, a, b, tol, max_iter)
    local fa = f(a)
    local fb = f(b)
    local iter = 0
    
    -- Checa pelo teorema do valor intermediario se existe algum candidato a raiz
    if fa * fb >= 0 then
        return nil, "Erro: Nao e possivel assegurar que ha uma raiz no intervalo"
    end
    
    -- Repete ate encontrar uma raiz ou o numero de iteracoes estourar
    while (b - a) / 2 > tol and iter < max_iter do
        local c = (a + b) / 2
        local fc = f(c)
        
        if fc == 0 then
            return c
        elseif fa * fc < 0 then
            b = c
            fb = fc
        else
            a = c
            fa = fc
        end
        
        iter = iter + 1
    end
    
    -- Retorna a aproximacao final
    local x = (a + b) / 2
    return x, iter
end

-- Chama a funcao e verifica se obteve exito ou nao.
local root, iterations = bisection_method(f, a, b, tol, max_iter)
if root then
    print("The root is approximately:", root)
    print("Number of iterations used:", iterations)
else
    print(iterations)
end
