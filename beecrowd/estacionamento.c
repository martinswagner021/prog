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

int vazia_pilha(Pilha* p){
    return p->topo == NULL;
}

int main(){

	Pilha* L = cria_pilha();
	
	int n, k, c, s, v;


	while(1){

		scanf("%d %d\n",&n, &k);
		if(n==0 && k==0) break;

		Pilha* p = cria_pilha();

		v = 1;

		for(int i=0;i<n;i++){
			scanf("%d %d", &c, &s);
				if(v){
					if(vazia_pilha(p) && k>0){
					       push_pilha(p, c, s);
					       k--;
					}

					else{
						while(c >= p->topo->saida){
							pop_pilha(p);
							k++;
							if(vazia_pilha(p)) break;
						}

						if(k<=0) v=0;
						else{
							push_pilha(p, c, s);
							k--;
							if(p->topo->prox != NULL){
								if(p->topo->chegada > p->topo->prox->chegada && p->topo->saida < p->topo->prox->saida) continue;
								else{
									v = 0;
								}
							}
						}
					}
				}
		}

		if(v) printf("Sim\n");
		else printf("Nao\n");

		libera_pilha(p);
    }	
}
