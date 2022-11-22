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

	p->topo = t->prox;
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

int verifica(Pilha* L, int c, int s, int *k){
	Item *n = (Item*) malloc(sizeof(Item));
	n = L->topo;
	
	if(L->topo != NULL){
		if(L->topo->saida < c){
			pop_pilha(L);
			(*k)++;
		}
		if((*k)>0){
		       push_pilha(L,c,s);
		       (*k)--;
		}
		else{
			return 0;
		}
	}
	else{
		push_pilha(L,c,s);
		(*k)--;
	}
}

int main(){

	Pilha* L = cria_pilha();
	
	int n, k, c, s, v;

	scanf("%d %d\n",&n, &k);

	while(n!=0&&k!=0){
		for(int i=0; i<n; i++){
			scanf("%d %d\n",&c, &s);
			v = verifica(L, c, s, &k);
			printf("%d\n", k);
		}

		if(v){
			while(L->topo!=NULL && L->topo->prox!=NULL){
				if(L->topo->prox->saida > L->topo->saida){
				       	pop_pilha(L);
				}
				else{
					v = 0;
				}
			}
			v ? printf("Sim\n") : printf("Nao\n");
		}
		else{
			printf("Nao\n");
		}
		// next case loop testing
		libera_pilha(L);
		scanf("%d %d",&n, &k);
	}
}
