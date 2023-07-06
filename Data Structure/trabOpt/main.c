#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

int main(){
    avl t = avl_inicializar();
    t = inserir(t, 2, malloc(sizeof(int)));
    t = inserir(t, 5, malloc(sizeof(int)));
    t = inserir(t, 1, malloc(sizeof(int)));
    t = inserir(t, 3, malloc(sizeof(int)));
    t = inserir(t, 4, malloc(sizeof(int)));
    imprimir(t);
}