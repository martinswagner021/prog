-- Tarefa 3
-- 1)
select * from peca;

update peca set peso = peso * 2 where cidade like "R%";

update peca set peso = peso / 2 where cidade like "R%";

-- 2)
select max(peso) from peca;

create temporary table max_peso_table as select max(peso) max_peso from peca;
delete from peca where peso = (
	select max_peso from max_peso_table
);
drop temporary table max_peso_table;

insert into peca values ("P4", "Martelo", "Amarelo", 21, "Rio de Janeiro");

-- 3)
describe peca;
insert into peca (codigo, nome, cor, peso, cidade)
select "P8", "Alicate", "Azul", max(peso), "São Gonçalo" from peca;

-- 4)
select * from fornece;

-- update fornece set qtde = qtde + 13 where codF = "F2" and codP = "P2";

-- Join
insert into fornece (codF, codP, qtde)
select f.codigo, p.codigo, 13 from fornecedor as f, peca as p where f.codigo = "F2" and p.codigo = "P2";

-- Subquery
insert into fornece (codF, codP, qtde)
select (select codigo from fornecedor where codigo = "F2"),
	(select codigo from peca where codigo = "P2"),
    13;

delete from fornece where codF = "F2" and codP = "P2";

