import ply.yacc as yacc
from lexico import tokens, analisados
import sys

# Definição das regras gramaticais
def p_programa(p):
    'programa : declaracoes bloco'

def p_bloco(p):
    'bloco : BEGIN comando lista_com END'

def p_declaracoes(p):
    'declaracoes : def_const def_tipos def_var def_rotina'

def p_def_const(p):
    '''
    def_const : constante def_const
              | empty
    '''

def p_const_valor(p):
    '''
    const_valor : PALAVRA
                | exp_mat
    '''


def p_def_tipos(p):
    '''
    def_tipos : tipo def_tipos
              | empty
    '''

def p_def_var(p):
    '''
    def_var : variavel def_var
            | empty
    '''

def p_def_rotina(p):
    '''
    def_rotina : rotina def_rotina
               | empty
    '''

def p_constante(p):
    "constante : CONST ID '=' const_valor ';'"

def p_tipo(p):
    "tipo : TYPE ID '=' tipo_dado ';'"

def p_variavel(p):
    "variavel : VAR campo ';'"

def p_campo(p):
    "campo : ID lista_id ':' tipo_dado"

def p_rotina(p):
    '''
    rotina : FUNCTION ID param_rotina ':' tipo_dado bloco_rotina
           | PROCEDURE ID param_rotina bloco_rotina
    '''

def p_param_rotina(p):
    '''
    param_rotina : '(' campos ')'
                 | empty
    '''

def p_bloco_rotina(p):
    'bloco_rotina : def_var bloco'

def p_lista_com(p):
    '''
    lista_com : ';' comando lista_com
              | empty
    '''

def p_comando(p):
    '''
    comando : ID nome atribuicao
            | WHILE exp_logica DO bloco_com
            | IF exp_logica THEN bloco_com else
            | FOR for DO bloco_com
            | WRITE const_valor
            | READ ID nome
    '''

def p_atribuicao(p):
    '''
    atribuicao : ATRIBUICAO exp
               | empty
    '''

def p_exp(p):
    '''
    exp : exp_mat
        | exp_logica
    '''

def p_exp_logica(p):
    '''
    exp_logica : param_logico op_logico exp_logica
               | '(' param_logico op_logico exp_logica ')'
               | param_logico
    '''

def p_param_logico(p):
    '''
    param_logico : parametro op_comp parametro
                 | parametro
    '''

def p_exp_mat(p):
    '''
    exp_mat : parametro op_mat exp_mat
            | '(' parametro op_mat exp_mat ')'
            | parametro
    '''

def p_parametro(p):
    '''
    parametro : ID nome
              | NUMERO
              | FALSE
              | TRUE
    '''

def p_nome(p):
    '''
    nome : '.' ID nome
         | '[' parametro ']'
         | '(' lista_param ')'
         | empty
    '''

def p_lista_param(p):
    '''
    lista_param : parametro ',' lista_param
                | parametro
                | empty
    '''

def p_lista_id(p):
    '''
    lista_id : ',' ID lista_id
             | empty
    '''

def p_campos(p):
    'campos : campo lista_campos'

def p_lista_campos(p):
    '''
    lista_campos : ';' campo lista_campos
                 | empty
    '''

def p_tipo_dado(p):
    '''
    tipo_dado : INTEGER
              | REAL
              | CHAR
              | BOOLEAN
              | ARRAY '[' NUMERO ']' OF tipo_dado
              | RECORD campos END
              | ID
    '''

def p_for(p):
    "for : ID ATRIBUICAO parametro TO parametro"

def p_else(p):
    '''
    else : ELSE bloco_com
         | empty
    '''

def p_bloco_com(p):
    '''
    bloco_com : bloco
              | comando
    '''

def p_op_logico(p):
    '''
    op_logico : AND
              | OR
    '''

def p_op_comp(p):
    '''
    op_comp : '>'
            | '<'
            | COMPARACAO
    '''

def p_op_mat(p):
    '''
    op_mat : '+'
           | '-'
           | '*'
           | '/'
    '''

def p_empty(p):
    'empty :'
    pass

# Tratamento de erros
def p_error(p):
    if p:
        print(f"Erro de sintaxe em '{p.value}', linha {p.lineno}")
    else:
        print("Erro de sintaxe no final do arquivo.")

# Construção do parser
parser = yacc.yacc()

while True:
   try:
       s = input('calc > ')
   except EOFError:
       break
   if not s: continue
   result = parser.parse(s)
   print(result)