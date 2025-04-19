use studies

describe projeto

describe funcionario

describe departamento

describe trabalha

select F.nome, P.titulo, D.nome from trabalha as T, funcionario as F, projeto as P, departamento as D where
    T.CPF = F.CPF and
    T.codigo = P.codigo and
    D.codigo = P.departamento

-- 1)
select titulo from projeto where codigo not in (
    select codigo from trabalha where cpf in (
        select CPF from funcionario where altura = (
            select max(altura) from funcionario
        )
    )
)

-- 2)
select nome, peso from funcionario where cpf in (
    select cpf from trabalha where codigo in (
        select codigo from projeto where departamento in (
            select codigo from departamento where nome = "Computação"
        )
    )
)

-- 3)
select * from funcionario where not exists (
    select * from projeto where not exists (
        select * from trabalha where
        funcionario.cpf = trabalha.cpf and
        projeto.codigo = trabalha.codigo
    )
)

delete from projeto where titulo = "Estrela"

insert into projeto values(8, "Estrela", "UFRJ", 4)

-- 4)
select nome, altura from funcionario where not exists (
    select * from projeto where
    departamento = (
        select codigo from departamento where nome = "Finanças"
    )
    and not exists (
        select * from trabalha where
        trabalha.cpf = funcionario.cpf and
        trabalha.codigo = projeto.codigo
    )
)

-- 5)
select nome, altura from funcionario where CPF in (
    select CPF from trabalha where funcao = "gerente"
)

-- 6)
select nome, altura from funcionario where CPF not in (
    select CPF from trabalha where funcao = "gerente"
)

-- 7)
select nome, altura from funcionario where CPF in (
    select CPF from trabalha where funcao != "gerente"
)

-- 8)
select nome from peca as p1 where (
    select count(*) from peca as p2 where peso>8
) < 3