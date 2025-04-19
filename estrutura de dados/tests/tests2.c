#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

int main(){
    fila eqs = inicializar();
    

    char nome[10] = "Furadeira";
    inserir(eqs, 1, nome, 2.5, 2019);
    inserir(eqs, 3, "Chave de Fenda", 0.3, 2010);
    inserir(eqs, 2, "Trena", 0.1, 2002);

    printeqs();
    
    eqs = destruir();
}
