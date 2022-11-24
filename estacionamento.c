#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int chegada;
	int saida;
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

void push_pilha(Pilha* p, int chegada, int saida){
	Item* n = (Item*) malloc(sizeof(Item));
	n->chegada = chegada;
	n->saida = saida;
	n->prox = p->topo;
	p->topo = n;
}

Item pop_pilha(Pilha* p){
	Item n; 
	Item *t = (Item*) malloc(sizeof(Item));

	t = p->topo;

	n.chegada=t->chegada;
	n.saida=t->saida;
	
	if(t->prox != NULL){
		p->topo = t->prox;
	}
	else p->topo = NULL;

	free(t);

	return n;
}

void print_pilha(Pilha* p){
	Item* n = p->topo;
	while(n != NULL){
		printf("chegada: %d, saida: %d\n", n->chegada, n->saida);
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

void verifica(Pilha* p){
	Item *n = (Item*) malloc(sizeof(Item));
	n = p->topo;
	int temp = n->saida;

	while(n->prox!=NULL){
		if(n->prox->saida > n->saida) pop_pilha(p);
		
		if(n==p->topo) return;
		n = p->topo;
	}
}

int main(){

	Pilha* L = cria_pilha();

	int n, k, c, s, v;

	scanf("%d %d\n",&n, &k);
	
	while(n!=0&&k!=0){
		for(int i=0; i<n; i++){
			scanf("%d %d\n",&c, &s);
			if(L->topo==NULL){
			       push_pilha(L,c,s);
			       k--;
			}
			else{
				if(L->topo->saida < c){
					pop_pilha(L);
					k++;
				}
				push_pilha(L,c,s);
				k--;
			}
		}
		
		verifica(L);
		if(L->topo->prox == NULL) printf("Sim\n");
		else printf("Nao\n");

		// next case testing loop
		libera_pilha(L);
		scanf("%d %d",&n, &k);
	}
}
