import sintatico

# ---------------------------------------
# Aluno: Wagner Martins
# Gerador de código intermediário para simplepascal
# ---------------------------------------

class GeradorCodigoIntermediario:
    def __init__(self):
        self.codigo_intermediario = []
        self.temp_counter = 0

    def gerar_codigo(self, arvore):
        metodo = f'gerar_{arvore[0].lower()}'
        return getattr(self, metodo, self.generic_gerar_codigo)(arvore)

    def generic_gerar_codigo(self, arvore):
        print(f"Gerador genérico chamado para: {arvore[0]}")

    def gerar_programa(self, arvore):
        _, declaracoes, bloco = arvore
        self.gerar_codigo(declaracoes)
        self.gerar_codigo(bloco)

    def gerar_declaracoes(self, arvore):
        _, consts, tipos, vars, rotinas = arvore
        self.gerar_codigo(consts)
        self.gerar_codigo(tipos)
        self.gerar_codigo(vars)
        self.gerar_codigo(rotinas)

    def gerar_def_const(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, const, resto = arvore
            self.gerar_codigo(const)
            self.gerar_codigo(resto)

    def gerar_def_tipos(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, tipo, resto = arvore
            self.gerar_codigo(tipo)
            self.gerar_codigo(resto)

    def gerar_def_var(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, var, resto = arvore
            self.gerar_codigo(var)
            self.gerar_codigo(resto)

    def gerar_def_rotina(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, rotina, resto = arvore
            self.gerar_codigo(rotina)
            self.gerar_codigo(resto)

    def gerar_bloco(self, arvore):
        _, comandos, lista_com = arvore
        self.gerar_codigo(comandos)
        for comando in lista_com:
            self.gerar_codigo(comando)

    def gerar_comando(self, arvore):
        if arvore[0] == 'ATRIBUICAO':
            _, id, atribuicao = arvore
            temp = self.gerar_codigo(atribuicao)
            self.codigo_intermediario.append(f'{id} := {temp}')
        elif arvore[0] == 'while':
            _, exp, bloco_com = arvore
            temp = self.gerar_codigo(exp)
            self.codigo_intermediario.append(f'while {temp} do')
            self.gerar_codigo(bloco_com)
        elif arvore[0] == 'if':
            _, exp, bloco_com, alternativa_else = arvore
            temp = self.gerar_codigo(exp)
            self.codigo_intermediario.append(f'if {temp} then')
            self.gerar_codigo(bloco_com)
            if alternativa_else:
                self.codigo_intermediario.append('else')
                self.gerar_codigo(alternativa_else)
        elif arvore[0] == 'for':
            _, for_comando, bloco_com = arvore
            self.gerar_codigo(for_comando)
            self.gerar_codigo(bloco_com)
        elif arvore[0] == 'write':
            _, const_valor = arvore
            temp = self.gerar_codigo(const_valor)
            self.codigo_intermediario.append(f'write {temp}')
        elif arvore[0] == 'read':
            _, id = arvore
            self.codigo_intermediario.append(f'read {id}')

    def gerar_constante(self, arvore):
        _, id, valor = arvore
        self.codigo_intermediario.append(f'{id} := {valor}')

    def gerar_tipo(self, arvore):
        _, id, tipo_dado = arvore
        self.codigo_intermediario.append(f'{id} : {tipo_dado}')

    def gerar_variavel(self, arvore):
        _, campos = arvore
        self.gerar_codigo(campos)

    def gerar_campos(self, arvore):
        if len(arvore) > 1 and arvore[1] is not None:
            _, campos = arvore
            for i in campos:
                self.gerar_codigo(i)

    def gerar_campo(self, arvore):
        _, ids, tipo_dado = arvore
        for id in ids:
            self.codigo_intermediario.append(f'{id} : {tipo_dado}')

    def gerar_rotina(self, arvore):
        if arvore[1] == 'function':
            _, _, id, params, tipo_retorno, bloco = arvore
            self.codigo_intermediario.append(f'function {id} : {tipo_retorno}')
            self.gerar_codigo(params)
            self.gerar_codigo(bloco)
        elif arvore[1] == 'procedure':
            _, id, params, bloco = arvore
            self.codigo_intermediario.append(f'procedure {id}')
            self.gerar_codigo(params)
            self.gerar_codigo(bloco)

    def gerar_bloco_rotina(self, arvore):
        _, var, comando = arvore
        self.gerar_codigo(var)
        self.gerar_codigo(comando)

    def gerar_parametros(self, arvore):
        _, campos = arvore
        self.gerar_codigo(campos)

    def gerar_atribuicao(self, arvore):
        _, _, exp = arvore
        return self.gerar_codigo(exp)

    def gerar_exp(self, arvore):
        _, param, exp_l1 = arvore
        temp1 = self.gerar_codigo(param)
        if exp_l1:
            temp2 = self.gerar_codigo(exp_l1)
            temp = self.novo_temp()
            self.codigo_intermediario.append(f'{temp} := {temp1} {exp_l1[1]} {temp2}')
            return temp
        return temp1

    def gerar_exp_l1(self, arvore):
        if arvore:
            _, op, exp = arvore
            temp = self.gerar_codigo(exp)
            return (op, temp)

    def gerar_exp_logica(self, arvore):
        if arvore:
            _, op, exp = arvore
            temp = self.gerar_codigo(exp)
            return (op, temp)

    def gerar_param_logico(self, arvore):
        if arvore:
            _, op, param = arvore
            temp = self.gerar_codigo(param)
            return (op, temp)

    def gerar_exp_l2(self, arvore):
        if len(arvore) == 4:
            _, op, exp, _ = arvore
            temp = self.gerar_codigo(exp)
            return (op, temp)
        elif len(arvore) == 5:
            _, param_logico, op_logico, exp, _ = arvore
            temp1 = self.gerar_codigo(param_logico)
            temp2 = self.gerar_codigo(exp)
            temp = self.novo_temp()
            self.codigo_intermediario.append(f'{temp} := {temp1} {op_logico} {temp2}')
            return temp

    def gerar_exp_const(self, arvore):
        if len(arvore) == 3:
            _, param, exp_const_l = arvore
            temp1 = self.gerar_codigo(param)
            if exp_const_l:
                temp2 = self.gerar_codigo(exp_const_l)
                temp = self.novo_temp()
                self.codigo_intermediario.append(f'{temp} := {temp1} {exp_const_l[1]} {temp2}')
                return temp
            return temp1
        elif len(arvore) == 6:
            _, param, op, exp_const, _ = arvore
            temp1 = self.gerar_codigo(param)
            temp2 = self.gerar_codigo(exp_const)
            temp = self.novo_temp()
            self.codigo_intermediario.append(f'{temp} := {temp1} {op} {temp2}')
            return temp

    def gerar_exp_const_l(self, arvore):
        if arvore:
            _, op, exp_const = arvore
            temp = self.gerar_codigo(exp_const)
            return (op, temp)

    def gerar_exp_com_group(self, arvore):
        _, param, param_logico, op_logico, exp_com = arvore
        temp1 = self.gerar_codigo(param)
        temp2 = self.gerar_codigo(param_logico)
        temp3 = self.gerar_codigo(op_logico)
        temp4 = self.gerar_codigo(exp_com)
        temp = self.novo_temp()
        self.codigo_intermediario.append(f'{temp} := {temp1} {temp2} {temp3} {temp4}')
        return temp

    def gerar_bloco_com(self, arvore):
        _, comando = arvore
        self.gerar_codigo(comando)

    def gerar_exp_com(self, arvore):
        if len(arvore) == 4:
            _, param, param_logico, exp_com_l = arvore
            temp1 = self.gerar_codigo(param)
            temp2 = self.gerar_codigo(param_logico)
            if exp_com_l:
                temp3 = self.gerar_codigo(exp_com_l)
                temp = self.novo_temp()
                self.codigo_intermediario.append(f'{temp} := {temp1} {param_logico[1]} {temp3}')
                return temp
            return temp1
        elif len(arvore) == 7:
            _, param, param_logico, op_logico, exp_com, _ = arvore
            temp1 = self.gerar_codigo(param)
            temp2 = self.gerar_codigo(param_logico)
            temp3 = self.gerar_codigo(exp_com)
            temp = self.novo_temp()
            self.codigo_intermediario.append(f'{temp} := {temp1} {param_logico[1]} {op_logico} {temp3}')
            return temp

    def gerar_exp_com_l(self, arvore):
        if arvore:
            _, op, exp_com = arvore
            temp = self.gerar_codigo(exp_com)
            return (op, temp)

    def gerar_parametro(self, arvore):
        if arvore[1] == 'id':
            _, _, id, nome = arvore
            if nome:
                temp = self.gerar_codigo(nome)
                return f'{id}{temp}'
            return id
        else:
            _, _, valor = arvore
            return valor

    def gerar_nome(self, arvore):
        if arvore:
            _, op, nome = arvore
            if op != '.':
                temp = ''.join([self.gerar_codigo(p) for p in nome])
                return f'{op}{temp}'
            return f'{op}{nome}'

    def novo_temp(self):
        self.temp_counter += 1
        return f't{self.temp_counter}'

def main():
    parser = sintatico.parser
    file_name = sys.argv[1]
    data = open(file_name, 'r').read()
    resultado = parser.parse(data, lexer=sintatico.lexer)
    gerador = GeradorCodigoIntermediario()
    gerador.gerar_codigo(resultado)
    for linha in gerador.codigo_intermediario:
        print(linha)

if __name__ == "__main__":
    main()