# ---------------------------------------
# Aluno: Wagner Martins
# Analisador lexico para simplepascal criado nas aulas
# ---------------------------------------
import ply.lex as lex
import sys

# Palavras reservadas
reservados = {
    'const': 'CONSTANTE',
    'begin': 'BEGIN',
    'end': 'END',
    'type': 'TYPE',
    'var': 'VAR',
    'integer': 'INTEGER',
    'real': 'REAL',
    'char': 'CHAR',
    'boolean': 'BOOLEAN',
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

literals = ['+','-','*','/','=',',',';',':','.','[',']','(',')','>','<']

tokens = [
    'ID',
    'NUMERO',
    'PALAVRA',
    'ATRIBUICAO'
] + list(reservados.values())

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

# Define a rule so we can track line numbers
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

# A string containing ignored characters (spaces and tabs)
t_ignore  = ' \t'

# Error handling rule
def t_error(t):
    print("Illegal character '%s'" % t.value[0])
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

# Abre e entrega o arquivo a ser analisado
file_name = sys.argv[1]
data = open(file_name, 'r').read()
lexer.input(data)

# Tokenize
# while True:
#     tok = lexer.token()
#     if not tok: 
#         break      # No more input
#     print(tok)

# Tokenize
while True:
    tok = lexer.token()
    if not tok: 
        break      # No more input
    print(tok.type, tok.value, tok.lineno)
