#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

int main(){
    avl t = avl_inicializar();
    int* x = (int*) malloc(sizeof(int));
    t = inserir(t, 1, malloc(sizeof(int)), sizeof(int));
    t = inserir(t, 3, malloc(sizeof(int)), sizeof(int));
    t = inserir(t, 2, malloc(sizeof(int)), sizeof(int));
    t = inserir(t, 4, x, sizeof(int));

    printf("nmr teste: %d\n", (int) buscar(t, 4));
    imprimir(t);
}