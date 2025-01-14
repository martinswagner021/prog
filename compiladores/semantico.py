# ---------------------------------------
# Aluno: Wagner Martins
# Analisador semantico para simplepascal criado nas aulas
# ---------------------------------------
import sys
from lexico import tokens, lexer
from sintatico import parser

# Classe para representar o analisador semântico
class AnalisadorSemantico:
    def __init__(self):
        self.tabela_simbolos = [{}]

    def analisar(self, arvore):
        metodo = f'analisar_{arvore[0].lower()}'
        return getattr(self, metodo, self.generic_analisar)(arvore)

    def generic_analisar(self, arvore):
        print(f"Analisador genérico chamado para: {arvore[0]}")

    def analisar_programa(self, arvore):
        _, declaracoes, bloco = arvore
        self.analisar(declaracoes) 
        self.analisar(bloco)

    def analisar_declaracoes(self, arvore):
        _, consts, tipos, vars, rotinas = arvore
        self.analisar(consts)
        self.analisar(tipos)
        self.analisar(vars)
        self.analisar(rotinas)

    def analisar_def_const(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, const, resto = arvore
            self.analisar(const)
            self.analisar(resto)

    def analisar_def_tipos(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, tipo, resto = arvore
            self.analisar(tipo)
            self.analisar(resto)

    def analisar_def_var(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, var, resto = arvore
            self.analisar(var)
            self.analisar(resto)

    def analisar_def_rotina(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, rotina, resto = arvore
            self.analisar(rotina)
            self.analisar(resto)

    def analisar_bloco(self, arvore):
        _, comandos, lista_com = arvore
        self.tabela_simbolos.append({})
        self.analisar(comandos)
        for comando in lista_com:
            self.analisar(comando)
        self.tabela_simbolos.pop()

    def analisar_comando(self, arvore):
        if arvore[0] == 'ATRIBUICAO':
            _, id, atribuicao = arvore
            if not self.verificar_variavel(id):
                print(f"Erro: Variável '{id}' não declarada.")
            self.analisar(atribuicao)
        elif arvore[0] == 'while':
            _, exp, bloco_com = arvore
            self.analisar(exp)
            self.analisar(bloco_com)
        elif arvore[0] == 'if':
            _, exp, bloco_com, alternativa_else = arvore
            self.analisar(exp)
            self.analisar(bloco_com)
            if alternativa_else:
                self.analisar(alternativa_else)
        elif arvore[0] == 'for':
            _, for_comando, bloco_com = arvore
            self.analisar(for_comando)
            self.analisar(bloco_com)
        elif arvore[0] == 'write':
            _, const_valor = arvore
            self.analisar(const_valor)
        elif arvore[0] == 'read':
            _, id = arvore
            if not self.verificar_variavel(id):
                print(f"Erro: Variável '{id}' não declarada.")

    def analisar_constante(self, arvore):
        _, id, valor = arvore
        if id in self.tabela_simbolos[-1]:
            print(f"Erro: Constante '{id}' já declarada.")
        else:
            self.tabela_simbolos[-1][id] = valor
            print(f"Constante '{id}' adicionada com valor: {valor}")

    def analisar_tipo(self, arvore):
        _, id, tipo_dado = arvore
        if id in self.tabela_simbolos[-1]:
            print(f"Erro: Tipo '{id}' já declarado.")
        else:
            self.tabela_simbolos[-1][id] = tipo_dado
            print(f"Tipo '{id}' adicionado com tipo de dado: {tipo_dado}")

    def analisar_variavel(self, arvore):
        _, campos = arvore
        self.analisar(campos)

    def analisar_campos(self, arvore):
        print(arvore)
        if len(arvore) > 1 and arvore[1] is not None:
            _, campos = arvore
            for i in campos:
                self.analisar(i)

    def analisar_campo(self, arvore):
        _, ids, tipo_dado = arvore
        for id in ids:
            if id in self.tabela_simbolos[-1]:
                print(f"Erro: Variável '{id}' já declarada.")
            else:
                self.tabela_simbolos[-1][id] = tipo_dado
                print(f"Variável '{id}' adicionada com tipo: {tipo_dado}")

    def analisar_rotina(self, arvore):
        if arvore[1] == 'function':
            _, _, id, params, tipo_retorno, bloco = arvore
            if id in self.tabela_simbolos[-1]:
                print(f"Erro: Função '{id}' já declarada.")
            else:
                self.tabela_simbolos[-1][id] = {'type': 'function', 'params': params, 'retorno': tipo_retorno}
            self.tabela_simbolos.append({})
            self.analisar(params)
            self.analisar(bloco)
            self.tabela_simbolos.pop()
        elif arvore[1] == 'procedure':
            _, id, params, bloco = arvore
            if id in self.tabela_simbolos[-1]:
                print(f"Erro: Procedimento '{id}' já declarado.")
            else:
                self.tabela_simbolos[-1][id] = {'type': 'procedure', 'params': params}
            self.tabela_simbolos.append({})
            self.analisar(params)
            self.analisar(bloco)
            self.tabela_simbolos.pop()

    def analisar_bloco_rotina(self, arvore):
        _, var, comando = arvore
        self.analisar(var)
        self.analisar(comando)

    def analisar_parametros(self, arvore):
        _, campos = arvore
        self.analisar(campos)


    def analisar_atribuicao(self, arvore):
        _, _, exp = arvore
        self.analisar(exp)

    def analisar_exp(self, arvore):
        _, param, exp_l1 = arvore
        self.analisar(param)
        if exp_l1:
            self.analisar(exp_l1)

    def analisar_exp_l1(self, arvore):
        if arvore:
            _, op, exp = arvore
            if op[0] == 'param_logico':
                self.analisar_param_logico(op)
            else:
                self.analisar(exp)

    def analisar_exp_logica(self, arvore):
        if arvore:
            _, op, exp = arvore
            self.analisar(exp)

    def analisar_param_logico(self, arvore):
        if arvore:
            _, op, param = arvore
            self.analisar(param)

    def analisar_exp_l2(self, arvore):
        print(arvore)
        if len(arvore) == 4:
            _, op, exp, _ = arvore
            self.analisar(exp)
        elif len(arvore) == 5:
            _, param_logico, op_logico, exp, _ = arvore
            self.analisar(param_logico)
            self.analisar(exp)

    def analisar_exp_const(self, arvore):
        if len(arvore) == 3:
            _, param, exp_const_l = arvore
            self.analisar(param)
            if exp_const_l:
                self.analisar(exp_const_l)
        elif len(arvore) == 6:
            _, param, op, exp_const, _ = arvore
            self.analisar(param)
            self.analisar(exp_const)

    def analisar_exp_const_l(self, arvore):
        if arvore:
            _, op, exp_const = arvore
            self.analisar(exp_const)

    def analisar_exp_com_group(self, arvore):
        _, param, param_logico, op_logico, exp_com = arvore
        self.analisar(param)
        self.analisar(param_logico)
        self.analisar(op_logico)
        self.analisar(exp_com)

    def analisar_bloco_com(self, arvore):
        _, comando = arvore
        self.analisar(comando)

    def analisar_exp_com(self, arvore):
        if len(arvore) == 4:
            _, param, param_logico, exp_com_l = arvore
            self.analisar(param)
            self.analisar(param_logico)
            if exp_com_l:
                self.analisar(exp_com_l)
        elif len(arvore) == 7:
            _, param, param_logico, op_logico, exp_com, _ = arvore
            self.analisar(param)
            self.analisar(param_logico)
            self.analisar(exp_com)

    def analisar_exp_com_l(self, arvore):
        if arvore:
            _, op, exp_com = arvore
            self.analisar(exp_com)

    def analisar_parametro(self, arvore):
        if arvore[1] == 'id':
            _, _, id, nome = arvore
            if not self.verificar_variavel(id):
                print(f"Erro: Variável '{id}' não declarada.")
            if nome:
                self.analisar(nome)
        else:
            _, _, valor = arvore

    def analisar_nome(self, arvore):
        if arvore:
            _, op, nome = arvore
            if op != '.':
                for p in nome:
                    self.analisar(p)

    def analisar_if(self, arvore):
            _, exp, bloco_com, alternativa_else = arvore
            self.analisar(exp)
            self.analisar(bloco_com)
            if alternativa_else:
                self.analisar(alternativa_else)
                
    def analisar_while(self, arvore):
        _, exp, bloco_com = arvore
        self.analisar(exp)
        self.analisar(bloco_com)
    
    def analisar_for(self, arvore):
        _, for_comando, bloco_com = arvore
        self.analisar(for_comando)
        self.analisar(bloco_com)

    def analisar_write(self, arvore):
        _, const_valor = arvore
        self.analisar(const_valor)

    def analisar_read(self, arvore):
        _, id = arvore
        if not self.verificar_variavel(id):
            print(f"Erro: Variável '{id}' não declarada.")

    def analisar_for_comando(self, arvore):
        _, id, param_inicial, param_final = arvore
        if not self.verificar_variavel(id):
            print(f"Erro: Variável '{id}' não declarada.")
        self.analisar(param_inicial)
        self.analisar(param_final)

    def verificar_variavel(self, id):
        for tabela in reversed(self.tabela_simbolos):
            if id in tabela:
                return True
        return False

def main():
    import sintatico
    parser = sintatico.parser
    file_name = sys.argv[1]
    data = open(file_name, 'r').read()
    resultado = parser.parse(data, lexer=sintatico.lexer)
    analisador = AnalisadorSemantico()
    analisador.analisar(resultado)

if __name__ == "__main__":
    main()
