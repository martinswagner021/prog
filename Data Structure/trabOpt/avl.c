#include<stdio.h>
#include<stdlib.h>

typedef struct avl{
    int info;
    int FB;
    struct avl *esq;
    struct avl *dir;
}avl;

// Funcoes matematicas para calculo de altura e balanceamento
int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int alturaArv(avl* a){
    if(a!=NULL){
        return 1+max(alturaArv(a->esq), alturaArv(a->dir));
    }
    return 0;
}

void ajustarFB(avl* a){
    if(a!=NULL){
        int he = alturaArv(a->esq);
        int hd = alturaArv(a->dir);
        a->FB = hd-he;

        ajustarFB(a->esq);
        ajustarFB(a->dir);
    }
}

avl* findElem(avl* a, int x){
    if(a!=NULL){
        if(x == a->info) return a;
        if(x < a->info) return findElem(a->esq, x);
        if(x > a->info) return findElem(a->dir, x);
    }
    return NULL;
}

int existeX(avl* a, int x){
    avl* y = findElem(a, x);
    if(y==NULL) return 0;
    return 1;
}

// Ao chamar a funcao, certifique-se de que nivel = 0
int nivelNoX(avl* a, int x, int nivel){
    if(a!=NULL){
        if(a->info==x) return nivel;
        if(x<a->info) return nivelNoX(a->esq, x, nivel+1);
        if(x>a->info) return nivelNoX(a->dir, x, nivel+1);
    }
    return -1;
}


// Metodos de print
void printArvPreOrdem(avl* a){
    if(a!=NULL){
        printf("%d\n", a->info);
        printArvPreOrdem(a->esq);
        printArvPreOrdem(a->dir);
    }
}
void printArvEmOrdem(avl* a){
    if(a!=NULL){
        printArvEmOrdem(a->esq);
        printf("%d\n", a->info);
        printArvEmOrdem(a->dir);
    }
}
void printArvPosOrdem(avl* a){
    if(a!=NULL){
        printArvPosOrdem(a->esq);
        printArvPosOrdem(a->dir);
        printf("%d\n", a->info);
    }
}

// Estrutura de fila pra impressao em largura
typedef struct lista{
    avl* info;
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

void insereFila(fila* p, avl *x){
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
    avl* v = t->info;

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

void printArvEmLargura(avl* a){
    if(a!=NULL){
        fila* f = criaFila();
        insereFila(f, a);
        while(f->ini!=NULL){
            a = f->ini->info;
            printf("%d\n", removeFila(f));
            if(a->esq!=NULL) insereFila(f, a->esq);
            if(a->dir!=NULL) insereFila(f, a->dir);
        }
        liberaFila(f);
    }
}

void printFolha(avl* a){
    if(a!=NULL){
        printFolha(a->esq);
        printFolha(a->dir);
        if(a->dir == NULL && a->esq == NULL) printf("%d\n", a->info);
    }
}

avl* rot_dir_simples(avl* x){
    avl* y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    
    return y;
}

avl* rot_esq_simples(avl* x){
    avl* y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    
    return y;
}

avl* rot_dir(avl* x){
    avl *y = x->esq;
    if(alturaArv(y->dir) > alturaArv(y->esq)){
        x->esq = rot_esq_simples(y);
        return rot_dir_simples(x);
    }
    else{
        return rot_dir_simples(x);
    }
}

avl* rot_esq(avl* x){
    avl *y = x->dir;
    if(alturaArv(y->esq) > alturaArv(y->dir)){
        x->dir = rot_dir_simples(y);
        return rot_esq_simples(x);
    }
    else{
        return rot_esq_simples(x);
    }
}

avl* inserirArv(avl* a, int x){
    if(a==NULL){
        a = (avl*) malloc(sizeof(avl));
        a->info = x;
        a->FB = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    if(x < a->info) a->esq = inserirArv(a->esq, x);
    if(x > a->info) a->dir = inserirArv(a->dir, x);

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

// Retorna a avlore com o elemento removido
avl* removerArv(avl* a, int x){
    if(a!=NULL){
        if(a->info==x){
            if(a->esq==NULL && a->dir==NULL){
                free(a);
                return NULL;
            }
            if(a->esq==NULL){
                avl* aux = a->dir;
                free(a);
                return aux;
            }
            if(a->dir==NULL){
                avl* aux = a->esq;
                free(a);
                return aux;
            }
            avl* aux = a->esq;
            while(aux->dir!=NULL) aux = aux->dir;
            a->info = aux->info;
            a->esq = removerArv(a->esq, aux->info);
        }
        if(x<a->info) a->esq = removerArv(a->esq, x);
        if(x>a->info) a->dir = removerArv(a->dir, x);

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

avl* liberaArv(avl* a){
    if(a!=NULL){
        liberaArv(a->esq);
        liberaArv(a->dir);
        free(a);
    }
    return NULL;
}