#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	char info;
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

void push_pilha(Pilha* p, char info){
	Item* n = (Item*) malloc(sizeof(Item));
	n->info = info;
	n->prox = p->topo;
	p->topo = n;
}

char pop_pilha(Pilha* p){
	char n; 
	Item *t = (Item*) malloc(sizeof(Item));

	t = p->topo;
	if(t==NULL){
		return '\0';
	}
	n = t->info;
	p->topo = t->prox;
	free(t);

	return n;
}

void print_pilha(Pilha* p){
	Item* n = p->topo;
	while(n != NULL){
		printf("info: %c\n", n->info);
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

	Pilha* L = cria_pilha();
	char leitura;
	int count = 0;

	while(scanf("%c", &leitura)!=EOF){
		if(leitura=='\n'){
			printf("%d\n", count);
			libera_pilha(L);
			count = 0;
		}
		else{
			if(L->topo == NULL){
				push_pilha(L, leitura);
			}
			else{
				switch(leitura){
					case 'B':
						if(L->topo->info == 'S'){
							pop_pilha(L);
							count++;
						}
						else{
							push_pilha(L, leitura);
						}
						break;
					case 'C':
						if(L->topo->info == 'F'){
							pop_pilha(L);
							count++;
						}
						else{
							push_pilha(L, leitura);
						}
						break;
					case 'F':
						if(L->topo->info == 'C'){
							pop_pilha(L);
							count++;
						}
						else{
							push_pilha(L, leitura);
						}
						break;
					case 'S':
						if(L->topo->info == 'B'){
							pop_pilha(L);
							count++;
						}
						else{
							push_pilha(L, leitura);
						}
						break;
				}
			}
		}

	}
}
