#include "avl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct avl{
    void* obj;
    int info;
    int FB;
    struct avl* esq;
    struct avl* dir;
};

// Funcoes matematicas para calculo de altura e balanceamento
int max(int a, int b){
    return (a >= b) ? a : b;
}

int alturaArv(avl a){
    if(a!=NULL){
        return 1+max(alturaArv(a->esq), alturaArv(a->dir));
    }
    return 0;
}

void ajustarFB(avl a){
    if(a!=NULL){
        int he = alturaArv(a->esq);
        int hd = alturaArv(a->dir);
        a->FB = hd-he;

        ajustarFB(a->esq);
        ajustarFB(a->dir);
    }
}

avl findElem(avl a, int x){
    if(a!=NULL){
        if(x == a->info) return a;
        if(x < a->info) return findElem(a->esq, x);
        if(x > a->info) return findElem(a->dir, x);
    }
    return NULL;
}

int buscar(avl a, int chave, void* obj, int tamObj){
    avl elem = findElem(a, chave);
    if(elem == NULL) return 0;
    memcpy(obj, elem->obj, tamObj);
    return elem->info;
}

int existe(avl a, int chave){
    avl y = findElem(a, chave);
    if(y==NULL) return 0;
    return 1;
}

// Estrutura de fila pra impressao em largura
typedef struct lista{
    avl info;
    struct lista* prox;
}lista;

typedef struct fila{
    struct lista* ini;
    struct lista* fim;
}fila;

fila* criaFila(){
    fila* p = (fila*) malloc(sizeof(fila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}

void insereFila(fila* p, avl x){
    lista* t = (lista*) malloc(sizeof(lista));
    t->info = x;
    t->prox = NULL;

    if(p->fim!=NULL) p->fim->prox = t;
    else p->ini = p->fim = t;

    p->fim = t;
}

int removeFila(fila* p){
    if(p->ini==NULL) return -1;

    lista* t = p->ini;
    avl v = t->info;

    p->ini = t->prox;
    if(p->ini == NULL) p->fim = NULL;
    free(t);
    return v->info;
}

void liberaFila(fila* p){
    lista* t = p->ini;
    while(t!=NULL){
        lista* l = t->prox;
        free(t);
        t=l;
    }
    free(p);
}

void imprimir(avl a){
    if(a!=NULL){
        fila* f = criaFila();
        insereFila(f, a);
        while(f->ini!=NULL){
            a = f->ini->info;
            printf("%d ", removeFila(f));
            if(a->esq!=NULL) insereFila(f, a->esq);
            if(a->dir!=NULL) insereFila(f, a->dir);
        }
        printf("\n");
        liberaFila(f);
    }
}

avl rot_dir_simples(avl x){
    avl y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    
    return y;
}

avl rot_esq_simples(avl x){
    avl y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    
    return y;
}

avl rot_dir(avl x){
    avl y = x->esq;
    if(alturaArv(y->dir) > alturaArv(y->esq)){
        x->esq = rot_esq_simples(y);
        return rot_dir_simples(x);
    }
    else{
        return rot_dir_simples(x);
    }
}

avl rot_esq(avl x){
    avl y = x->dir;
    if(alturaArv(y->esq) > alturaArv(y->dir)){
        x->dir = rot_dir_simples(y);
        return rot_esq_simples(x);
    }
    else{
        return rot_esq_simples(x);
    }
}

avl inserir(avl a, int chave, void* obj, int tamObj){
    if(a==NULL){
        a = (avl) malloc(sizeof(struct avl));
        a->obj = malloc(tamObj);
        memcpy(a->obj, obj, tamObj);
        a->info = chave;
        a->FB = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    if(chave < a->info) a->esq = inserir(a->esq, chave, obj, tamObj);
    if(chave > a->info) a->dir = inserir(a->dir, chave, obj, tamObj);

    ajustarFB(a);
    if(!(a->FB >= -1 && a->FB<=1)){
        // Esta desbalanceada na direita
        if(a->FB > 0){
            // rotacionar a esq
            return rot_esq(a);
        }
        // Esta desbalanceada na esquerda
        if(a->FB < 0){
            // rotacionar a dir
            return rot_dir(a);
        }
    }
    return a;
}

avl remover(avl a, int chave){
    if(a!=NULL){
        if(a->info==chave){
            if(a->esq==NULL && a->dir==NULL){
                free(a);
                return NULL;
            }
            if(a->esq==NULL){
                avl aux = a->dir;
                free(a);
                return aux;
            }
            if(a->dir==NULL){
                avl aux = a->esq;
                free(a);
                return aux;
            }
            avl aux = a->esq;
            while(aux->dir!=NULL) aux = aux->dir;
            a->info = aux->info;
            a->obj = aux->obj;
            a->esq = remover(a->esq, aux->info);
        }
        if(chave<a->info) a->esq = remover(a->esq, chave);
        if(chave>a->info) a->dir = remover(a->dir, chave);

        ajustarFB(a);
        if(!(a->FB >= -1 && a->FB<=1)){
            // Esta desbalanceada na direita
            if(a->FB > 0){
                // rotacionar a esq
                return rot_esq(a);
            }
            // Esta desbalanceada na esquerda
            if(a->FB < 0){
                // rotacionar a dir
                return rot_dir(a);
            }
        }
    }
    return a;
}

avl avl_inicializar(){
    return NULL;
}

avl avl_destruir(avl a){
    if(a!=NULL){
        avl_destruir(a->esq);
        avl_destruir(a->dir);
        free(a->obj);
        free(a);
    }

    return NULL;
}