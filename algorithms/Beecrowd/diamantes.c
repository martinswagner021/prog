#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct lista{
    char info;
    struct lista* prox;
} Lista;

Lista* cria_lista(){
    return NULL;
}

Lista* insere_lista(Lista* L, char info){
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->info = info;
    p->prox = L;

    return p;
}

void libera_lista(Lista* L){
    while(L!=NULL){
        Lista* t = L;
        L = L->prox;
        free(t);
    }
}

void print_lista(Lista* L){
    for(Lista* p = L; p != NULL; p=p->prox) printf("%c", p->info);
    printf("\n");
    // if(L != NULL){
    //     print_lista(L->prox);
    //     printf("%c", L->info);
    // }
}

Lista* remove_elemen(Lista* L, char info){
    Lista *p = L, *ant = NULL;
    
    while(p!=NULL && p->info != info){
        ant=p;
        p=p->prox;
    }
    if(p==NULL) return L;
    
    if(ant==NULL) L = p->prox;
    else{
        ant->prox = p->prox;
    }

    count++;
    free(p);
    return L;
}

void processa_diamante(Lista* L){
    if(L!=NULL){
        if(L->info == '>') remove_elemen(L,'<');
        processa_diamante(L->prox);
    }
}

int main () {

    int n;
    char elem;

    scanf("%d\n",&n);
    for(int i=0; i<n; i++){
        // Cria e le lista
        Lista* L = cria_lista();
        scanf("%c", &elem);
        while(elem != '\n' && elem != '\0'){
            L = insere_lista(L, elem);
            scanf("%c", &elem);
        }

	    // Processa
        processa_diamante(L);

        // Libera lista
        libera_lista(L);
        printf("%d\n", count);
        count = 0;
    }

}
