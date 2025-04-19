#include "stdio.h"
#include "stdlib.h"
#include "avl.h"

int main(){
    avl numeros = avl_inicializar();
    int *x = (int *) malloc(sizeof(int));
    *x = 1;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 2;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 3;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 4;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 5;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 6;
    numeros = inserir(numeros, *x, x, sizeof(int));
    *x = 7;
    numeros = inserir(numeros, *x, x, sizeof(int));
    numeros = remover(numeros, 4);
    numeros = remover(numeros, 1);
    imprimir(numeros);
    numeros = avl_destruir(numeros);
}