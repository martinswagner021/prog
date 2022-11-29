#include<stdio.h>
#include<stdlib.h>

typedef struct item{
        int info;
        struct item *prox;
        struct item *ant;
} Item;

typedef struct lista{
        Item *ini;
	Item *fim;
} Lista;

Lista* cria_lista(){
        Lista* p = (Lista*) malloc(sizeof(Lista));
        p->ini = NULL;
        p->fim = NULL;
        return p;
}

Lista* insert(Lista *L, int info){
        Item *n = (Item*) malloc(sizeof(Item));
        n->info = info;
        if(L->ini == NULL){
                L->ini = n;
                L->fim = n;

                return L;
        }

        n->prox = L->ini;
	L->ini->ant = n;
        L->ini = n;

        return L;
}

int pop(Lista *L){
        Item *n = L->fim;
	int t = n->info;

	if(n->ant == NULL){
		L->ini = NULL;
	}
	L->fim = n->ant;
	n->ant->prox = NULL;
	free(n);
        return t;
}

void print_posordem(Item* ini){
        if(ini != NULL){
                printf("%d ", ini->info);
                print_posordem(ini->prox);
        }
}

void libera_lista(Lista* L){
        Item *n = L->ini;
        while(n!=NULL){
                Item *t = n;
                n=t->prox;
                free(t);
        }
        L->ini = NULL;
        L->fim = NULL;
}

int main(){
	int t, k, ki, n;

	Lista* L = cria_lista();
	
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf(" %d %d", &k, &n);
		for(int j=0; j<k; j++){
			insert(L, j);
		}
		if(n<=k){
			Item *temp = L->fim;

			for(int j=1; j<n; j++){
				temp = temp->ant;
			}
			printf("%d\n", temp->info);
		}
		else{
			
			int sum = 0;
			for(Item* t = L->ini; t != NULL; t=t->prox){
				sum = sum+t->info;
			}
			for(int l=k; l<n; l++){
				insert(L, sum);
				sum = ((sum%1000007)+(sum%1000007)+1000007)%1000007;
				sum = (sum-pop(L)+1000007)%1000007;
			}
			printf("%d\n", L->ini->info);
		}
		libera_lista(L);
	}
}
