#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

typedef struct elementoFila{
    int info;
    struct elementoFila *prox;
}lista;

struct fila{
    lista *ini;
    lista *fim;
};


void filaInserir(fila p, int info){
    lista* n = (lista*) malloc(sizeof(lista));
    n->info = info;
    n->prox = NULL;

    if(filaIsVazia(p)){
        p->ini = n;
    }
    else{
        p->fim->prox = n;
    }
    p->fim = n;
}

int filaRemover(fila p){
    if(filaIsVazia(p)){
        return -1;
    }
    lista* aux = p->ini;
    int info = aux->info;
    p->ini = aux->prox;

    if(filaIsVazia(p)){
        p->fim = NULL;
    }

    free(aux);
    return info;
}

int filaIsVazia(fila p){
    return (p->ini == NULL);
}

void filaImprimir(fila p){
    printf("[");
    for(lista* t = p->ini; t!=NULL; t = t->prox) (t->prox == NULL) ? printf("%d", t->info) : printf("%d ", t->info);
    printf("]\n");
}

void filaDestruir(fila p){
    lista* t = p->ini;
    lista* aux;
    while(t != NULL){
        aux = t;
        t = t->prox;
        free(aux);
    }
    free(p);
}

fila filaInicializar(){
    fila p = (fila) malloc(sizeof(struct fila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}