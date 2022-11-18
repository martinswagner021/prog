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
	if(L->last == NULL){
		L->ini = n;
		L->last = n;
		L->fim = n;

		return L;
	}

	n->prox = L->last->prox;
	L->last->prox = n;
	L->last = n;
	
	return L;
}


void print_posordem(Item* ini){
	if(ini != NULL){
		print_posordem(ini->prox);
		printf("%c ", ini->info);
	}
}

int main(){
	Lista* L = cria_lista();
	append_lastmod(L, '1');
	append_lastmod(L, '2');
	append_lastmod(L, '3');
	append_lastmod(L, '4');
	append_lastmod(L, '5');
	append_lastmod(L, '6');
	append_lastmod(L, '7');
	
	print_posordem(L->ini);
	

//	while(scanf("%c",&leitura)!=EOF){
//		// do something
//	}
}
