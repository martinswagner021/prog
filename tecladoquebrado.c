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

void insere_fim_lista(Lista **L, char info){
	Item *n = (Item*) malloc(sizeof(Item));
	n->info = info;
	n->prox = NULL;

	if((*L)->ini == NULL){
		(*L)->ini = n;
	}

	(*L)->fim->prox = n;
	(*L)->fim = n;
	(*L)->last = n;
}

void print_posordem(Item* ini){
	if(ini != NULL){
		print_posordem(ini->prox);
		printf("%c\n", ini->info);
	}
}
int main(){
	Lista* L = cria_lista();
	insere_fim_lista(&L, '1');
	insere_fim_lista(&L, '2');
	insere_fim_lista(&L, '3');
	insere_fim_lista(&L, '4');
	insere_fim_lista(&L, '5');
	insere_fim_lista(&L, '6');
	insere_fim_lista(&L, '7');
	insere_fim_lista(&L, '8');
	
	//print_posordem(L->ini);
	

//	while(scanf("%c",&leitura)!=EOF){
//		// do something
//	}
}
