#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int info;
	struct item *prox;
} Item;

typedef struct pilha{
	Item *topo;
} Pilha;

Pilha* cria_pilha(){
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

void push_pilha(Pilha* p, int info){
	Item* n = (Item*) malloc(sizeof(Item));
	n->info = info;
	n->prox = p->topo;
	p->topo = n;
}

int pop_pilha(Pilha* p){
	char n; 
	Item *t = (Item*) malloc(sizeof(Item));

	t = p->topo;
	if(t==NULL){
		return 0;
	}
	n = t->info;
	p->topo = t->prox;
	free(t);

	return n;
}

void print_pilha(Pilha* p){
	Item* n = p->topo;
	while(n != NULL){
		printf("%d ", n->info);
		n=n->prox;
	}
}

void libera_pilha(Pilha* p){
	Item *n = (Item*) malloc(sizeof(Item));
	n = p->topo;
	while(n!=NULL){
		Item *t = n;
		n=n->prox;
		free(t);
	}
	p->topo = NULL;
}

int main(){

	int n, s;
	Pilha *L = cria_pilha();
	scanf("%d", &n);
	while(n!=0){
		Pilha *P = cria_pilha();
		for(int i=n; i>0; i--) push_pilha(L, i);

		scanf("%d", &s);
		while(s!=0){
			for(int i=0; i<n; i++){
				int temp;
				scanf("%d", &temp);
				push_pilha(P, temp);
			}

			print_pilha(P);

			//prepara proximo loop
			scanf(" %d", &s);
		}
		//prepara proximo loop
		scanf("%d", &n);
		libera_pilha(L);
	}
	
}
