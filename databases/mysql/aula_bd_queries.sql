select * from peca;
select * from fornecedor;
select * from fornece;

select f.cidade, p.cidade from fornecedor as f, peca as p;

select nome from fornecedor, fornece where codigo = codF and codP="P1";

-- Tarefa 1
-- 1)
select distinct fornecedor.codigo from fornecedor, fornece, peca where
	fornecedor.codigo = codF and
    peca.codigo = codP and
    peca.nome like "P%";
    
-- 2)
select peca.nome, peca.cidade from peca, fornece, fornecedor where
	peca.codigo = codP and
    fornecedor.codigo = codF and
	fornecedor.cidade = "Rio das Ostras";
    
--  3)
select fornecedor.nome from fornecedor, fornece, peca where
	fornecedor.codigo = codF and
    peca.codigo = codP and
    peca.codigo = "P1";

-- Tarefa 2
-- 1)
select p.nome, p.peso, p.cidade from peca as p where p.codigo in (
	select codP from fornece where codF in (
		select f.codigo from fornecedor as f where f.cidade = "Rio das Ostras"
	)
);

-- 2) IN
select f.nome from fornecedor as f where f.codigo not in (
	select codF from fornece
);

-- 2) EXISTS
select f.codigo from fornecedor as f where not exists (
	select * from fornece where f.codigo = codF
);

-- 3)
select nome from peca where peso = (
	select max(peso) from peca
) union
select nome from peca where peso = (
	select max(peso) from peca where codigo in (
		select codigo from peca where peso < (
			select max(peso) from peca
		)
	)
) union
select nome from peca where peso = (
	select max(peso) from peca where codigo in (
		select codigo from peca where peso < (
			select max(peso) from peca where codigo in (
				select codigo from peca where peso < (
					select max(peso) from peca
				)
			)
		)
	)
);

-- 3) order by + limit
select nome from peca order by peso desc limit 3;

-- 4) IN
select f.nome from fornecedor as f where f.codigo in (
	select codF from fornece
) and f.codigo not in (
	select codF from fornece where codP = "p1"
);

-- 4) EXISTS
select f.nome from fornecedor as f where exists (
	select * from fornece where f.codigo = codF
) and not exists (
	select * from fornece where f.codigo = codF and codP = "p1"
);

-- 5)
select p.nome from peca as p where p.peso = (
	select min(p.peso) from peca as p
);
