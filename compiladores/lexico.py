# ---------------------------------------
# Aluno: Wagner Martins
# Analisador lexico para simplepascal criado nas aulas
# ---------------------------------------
import ply.lex as lex
import sys

# Palavras reservadas
reservados = {
    'const': 'CONST',
    'begin': 'BEGIN',
    'end': 'END',
    'type': 'TYPE',
    'var': 'VAR',
    'integer': 'INTEGER',
    'real': 'REAL',
    'char': 'CHAR',
    'boolean': 'BOOLEAN',
    'array': 'ARRAY',
    'of': 'OF',
    'record': 'RECORD',
    'function': 'FUNCTION',
    'procedure': 'PROCEDURE',
    'while': 'WHILE',
    'do': 'DO',
    'if': 'IF',
    'then': 'THEN',
    'for': 'FOR',
    'write': 'WRITE',
    'read': 'READ',
    'to': 'TO',
    'else': 'ELSE',
    'false': 'FALSE',
    'true': 'TRUE',
    'and': 'AND',
    'or': 'OR',
}

# Tokens literais, possuem como nome o mesmo simbolo que os define
literals = ['+','-','*','/','=',',',';',':','.','[',']','(',')']

# Definicao dos tokens + uniao das palavras reservadas
tokens = [
    'ID',
    'NUMERO',
    'PALAVRA',
    'ATRIBUICAO',
    'COMPARACAO'
] + list(reservados.values())

# Expressoes regulares dos tokens simples
t_ATRIBUICAO = ':='
t_COMPARACAO = r'<=|>=|==|!=|<|>'

def t_NUMERO(t):
    r'\d+(\.\d+)?'
    t.value = float(t.value) if '.' in t.value else int(t.value)
    return t

def t_ID(t):
    r'[a-zA-Z_][a-zA-Z_0-9]*'
    t.type = reservados.get(t.value,'ID')
    t.value = str(t.value)
    return t

def t_PALAVRA(t):
    r'"[A-Za-z0-9\s]*"'
    t.value = str(t.value)
    return t

# Regra para determinar posicao da linha do codigo
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

# Caracteres ignorados pelo analisador lexico, espacos e tabulacoes
t_ignore  = ' \t'

# Tratamento de erro quando um caracter nao e identificado pelo analisador
def t_error(t):
    print(f"Caracter {t.value[0]} nao identificado.")
    # Pula o elemento para que identifique outros possiveis erros na mesma analise
    t.lexer.skip(1)

# Compila as regras definidas para o lexer
lexer = lex.lex()

# Abre e entrega o arquivo a ser analisado
file_name = sys.argv[1]
data = open(file_name, 'r').read()
lexer.input(data)

# Define uma classe para armazenar os tokens
class Token():
    def __init__(self, token):
        self.tipo = tok.type
        self.valor = tok.value
        self.linha = tok.lineno
analisados = list()

# Analisa os tokens do arquivo
while True:
    tok = lexer.token()
    if not tok: 
        break
    analisados.append(tok)