select * from peca;
select * from fornecedor;
select * from fornece;

select f.cidade, p.cidade from fornecedor as f, peca as p;

select nome from fornecedor, fornece where codigo = codF and codP="P1";

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


