#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
	int chegada;
	int saida;
	struct lista *prox;
} Lista;

typedef struct pilha{
	Lista *prim;
} Pilha;

Pilha* cria_pilha(){
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}

void push_pilha(Pilha* p, int chegada, int saida){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->chegada = chegada;
	n->saida = saida;
	n->prox = p->prim;
	p->prim = n;
}

int main(){

	int n, k, c, s;

	scanf("%d",&n);
	scanf("%d",&k);
	
	while(n!=0&&k!=0){
		for(int i=0; i<n; i++){
			scanf("%d",&c);
			scanf("%d",&s);
			
		}
	}
}
