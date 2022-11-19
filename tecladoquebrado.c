#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	char info;
	struct item *prox;
} Item;

typedef struct lista{
	Item *ini;
	Item *last;
	Item *fim;
} Lista;

Lista* cria_lista(){
	Lista* p = (Lista*) malloc(sizeof(Lista));
	p->ini = NULL;
	p->last = NULL;
	p->fim = NULL;
	return p;
}

Lista* append(Lista *L, char info){
	Item *n = (Item*) malloc(sizeof(Item));
	n->info = info;
	n->prox = NULL;

	if(L->ini == NULL){
		L->ini = n;
		L->last = n;
		L->fim = n;

		return L;
	}

	L->fim->prox = n;
	L->fim = n;
	L->last = n;

	return L;
}

Lista* append_lastmod(Lista *L, char info){
	Item *n = (Item*) malloc(sizeof(Item));
	n->info = info;
	if(L->ini == NULL){
		L->ini = n;
		L->last = n;
		L->fim = n;

		return L;
	}
	
	if(L->last->prox == NULL){
		L->fim = n;
	}
	
	n->prox = L->last->prox;
	L->last->prox = n;
	L->last = n;

	return L;
}

Lista* insert_beginning(Lista *L, char info){
	Item *n = (Item*) malloc(sizeof(Item));
	n->info = info;
	if(L->ini == NULL){
		L->ini = n;
		L->last = n;
		L->fim = n;

		return L;
	}
	
	n->prox = L->ini;
	L->ini = n;
	L->last = n;

	return L;
}

void print_posordem(Item* ini){
	if(ini != NULL){
		printf("%c", ini->info);
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
	L->last = NULL;
	L->fim = NULL;
}

int main(){
	Lista* L = cria_lista();

	char leitura;
	
	int toggletext=0;
	
	while(scanf("%c",&leitura)!=EOF){
		switch(leitura){
			case '[':
				toggletext = 1;
				break;
			case '\n':
				print_posordem(L->ini);
				printf("\n");
				toggletext = 0;
				libera_lista(L);
				break;

			case']':
				toggletext = 2;
				break;
			default:
				if(toggletext==1) insert_beginning(L, leitura);
				if(toggletext==2) append(L, leitura);
				if(toggletext==0) append_lastmod(L, leitura);

				toggletext = 0;
				break;
		}
	}
}
