import pymysql
import os
import socket
from dotenv import load_dotenv
load_dotenv()

server = f'{socket.gethostname()}.local'


# Abrindo uma conexão com o banco de dados
conexao = pymysql.connect(db='studies', user='root', passwd=os.getenv('DB_SECRET'), host=server)

# Criando um cursor
cursor = conexao.cursor()

# Removendo dados das tabelas
cursor.execute("DELETE FROM trabalha")
cursor.execute("DELETE FROM projeto")
cursor.execute("DELETE FROM funcionario")
cursor.execute("DELETE FROM departamento")

# Inserindo dados na tabela Departamento
dados = " INSERT INTO departamento VALUES " + \
            "(1, 'Computação'), " + \
            "(2, 'Finanças'), " + \
            "(3, 'Compras'), " + \
            "(4, 'RH') "

cursor.execute(dados)

# Inserindo dados na tabela Projeto
dados = " INSERT INTO Projeto VALUES " + \
            "(1, 'Ambiental', 'Nature', 2), " + \
            "(2, 'Viva', 'Vivo', 2), " + \
            "(3, 'BOP', 'Pet', 1), " + \
            "(4, 'DT', 'Pet', 1), " + \
            "(5, 'Obra', 'UFF', 4), " + \
            "(6, 'Criança', 'UFF', 3), " + \
            "(7, 'Ensino', 'UFF', 3), " + \
            "(8, 'Estrela', 'UFRJ', 4) "

cursor.execute(dados)

# Inserindo dados na tabela Funcionário
dados = " INSERT INTO Funcionario VALUES " + \
            "(1, 'João', 87, 1.80), " + \
            "(2, 'Maria', 47, 1.43), " + \
            "(3, 'Melissa', 55, 1.51), " + \
            "(4, 'Mel', 62, 1.55), " + \
            "(5, 'Ana', 60, 1.60), " + \
            "(6, 'Pedro', 66, 1.70), " + \
            "(7, 'Cássio', 55, 1.61), " + \
            "(8, 'José', 90, 2.00), " + \
            "(9, 'Júnior', 61, 1.71), " + \
            "(10, 'Valéria', 63, 1.57), " + \
            "(11, 'Léo', 76, 1.80), " + \
            "(12, 'André', 48, 1.50), " + \
            "(13, 'Viviane', 59, 1.58) "

cursor.execute(dados)

# Inserindo dados na tabela Trabalha
dados = " INSERT INTO trabalha (CPF, codigo, funcao) VALUES " + \
            "(1, 1, 'gerente'), " + \
            "(2, 1, 'analista'), " + \
            "(3, 1, 'analista'), " + \
            "(4, 1, 'analista'), " + \
            "(5, 1, 'analista'), " + \
            "(6, 1, 'analista'), " + \
            "(7, 1, 'analista'), " + \
            "(8, 1, 'analista'), " + \
            "(9, 1, 'analista'), " + \
            "(10, 1, 'analista'), " + \
            "(11, 1, 'analista'), " + \
            "(12, 1, 'analista'), " + \
            "(1, 2, 'analista'), " + \
            "(2, 2, 'gerente'), " + \
            "(3, 2, 'analista'), " + \
            "(4, 2, 'analista'), " + \
            "(5, 2, 'analista'), " + \
            "(6, 2, 'analista'), " + \
            "(7, 2, 'analista'), " + \
            "(8, 2, 'analista'), " + \
            "(9, 2, 'analista'), " + \
            "(10, 2, 'analista'), " + \
            "(13, 2, 'analista'), " + \
            "(1, 3, 'analista'), " + \
            "(2, 3, 'analista'), " + \
            "(3, 3, 'gerente'), " + \
            "(4, 3, 'analista'), " + \
            "(5, 3, 'analista'), " + \
            "(6, 3, 'analista'), " + \
            "(1, 4, 'analista'), " + \
            "(2, 4, 'analista'), " + \
            "(3, 4, 'gerente'), " + \
            "(4, 4, 'analista'), " + \
            "(5, 4, 'analista'), " + \
            "(1, 5, 'analista'), " + \
            "(2, 5, 'analista'), " + \
            "(3, 5, 'analista'), " + \
            "(4, 5, 'gerente'), " + \
            "(5, 5, 'analista'), " + \
            "(6, 5, 'analista'), " + \
            "(1, 6, 'analista'), " + \
            "(2, 6, 'analista'), " + \
            "(3, 6, 'analista'), " + \
            "(4, 6, 'analista'), " + \
            "(1, 7, 'analista'), " + \
            "(2, 7, 'analista'), " + \
            "(3, 7, 'gerente') "

cursor.execute(dados)

# Inserindo dados na tabela Fornece
'''dados = " INSERT INTO fornece (codF, codP, qtde) VALUES " + \
            "('F1', 'P2', 10), " + \
            "('F1', 'P4', 23), " + \
            "('F3', 'P1', 10), " + \
            "('F3', 'P2', 15), " + \
            "('F3', 'P3', 21), " + \
            "('F3', 'P4', 14), " + \
            "('F4', 'P3', 8)"

cursor.execute(dados)'''

# Efetua um commit no banco de dados.
# Por padrão, não é efetuado commit automaticamente. Você deve commitar para salvar
# suas alterações.
conexao.commit()

# Finaliza a conexão
conexao.close()
