#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "fila.h"

typedef struct lista{
    int id;
    char nome[50];
    float peso;
    int anoFabricacao;
    struct lista* prox;
}lista;

struct fila{
    lista* ini;
    lista* fim;
};

fila inicializar(){
    fila f = (fila) malloc(sizeof(struct fila));
    f->ini = f->fim = NULL;
    return f;
}

fila destruir(fila f){
    lista* t = f->ini;
    lista* aux = NULL;
    while (t != NULL){
        aux = t->prox;
        free(t);
        t = aux;
    }
    free(f);
    return NULL;
}

void inserir(fila f, int id, char* nome, float peso, int anoFabricacao){
    lista* eq = (lista*) malloc(sizeof(lista));
    eq->id = id;
    eq->peso = peso;
    eq->anoFabricacao = anoFabricacao;
    strcpy(eq->nome, nome);
    eq->prox = NULL;

    // if(f->ini == NULL){
    //     f->ini = f->fim = eq;
    // }
    // else{
    //     f->fim->prox = eq;
    //     f->fim = eq;
    // }
}

lista* remover(fila f){
    if (f->ini != NULL){
        lista* aux = f->ini;
        f->ini = aux->prox;
        return aux;
    }
    return NULL;
}

void printeqs(fila f){
    // for (lista* i = f->ini; i!=NULL; i=i->prox) printf("%d\n", i->id);
    // printf("%s", f->ini->nome);
}
