# ---------------------------------------
# Aluno: Wagner Martins
# Compilador para simple pascal criado nas aulas
# ---------------------------------------
from lexico import lexer, analisados
from sintatico import parser
import sys

try:
    # Leitura do arquivo
    with open(sys.argv[1], 'r') as file:
        data = file.read()
    # Reset no contador para o sintatico depois de analisar o lexico
    lexer.lineno = 1

    result = parser.parse(data)

    # Debug arg
    if '--debug' in sys.argv:
        # Debug do lexico
        for tok in analisados:
            print(tok)
        # Debug do sintatico
        print(result)

except FileNotFoundError:
    print(f"Erro: Arquivo '{sys.argv[1]}' não encontrado!")
except Exception as e:
    print(f"Erro ao analisar o arquivo: {e}")