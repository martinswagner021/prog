#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int info;
	struct item *prox;
} Item;

typedef struct pilha{
	Item *topo;
	Item *fim;
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
	if(t->prox==NULL){
		p->fim = NULL;
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
	p->fim = NULL;
}

//serve para obter a ordem correta desejada pelo chefe, um append de fila
Pilha* emenda_pilha(Pilha *L, int info){
        Item *n = (Item*) malloc(sizeof(Item));
        n->info = info;
        n->prox = NULL;

        if(L->topo == NULL){
                L->topo = n;
                L->fim = n;

                return L;
        }

        L->fim->prox = n;
        L->fim = n;

        return L;
}

int vazia_pilha(Pilha *p){
	return (p->topo == NULL);
}

int main(){

	int n, temp, stop=0, i;
	
	Pilha *chegando = cria_pilha();
	Pilha *estacao = cria_pilha();
	Pilha *saindo = cria_pilha();
	
	//leitura e preenchimento da pilha para o caso teste
	scanf("%d", &n);

	while(n!=0){
		while(!stop){

			for(i=n; i>0; i--) push_pilha(chegando, i);
			//le a ordem desejada pelo chefe
			for(i=0; i<n && !stop; i++){

				//le elemento
				scanf(" %d", &temp);

				//verifica se deve ser interrompida a leitura
				if(!temp) stop = 1;
				if(!stop) emenda_pilha(saindo, temp);
			}

			int pos = 1;
			//processa possibilidade yes or no
			while(!vazia_pilha(saindo) && pos && !stop){
				if(vazia_pilha(estacao)) push_pilha(estacao, pop_pilha(chegando));
				else{
					if(estacao->topo->info == saindo->topo->info){
						pop_pilha(estacao);
						pop_pilha(saindo);
					}
					else{
						if(!vazia_pilha(chegando)) push_pilha(estacao, pop_pilha(chegando));
						else {
							pos = 0;
							//debugging
							//printf("chegando: ");
							//print_pilha(chegando);
							//printf("\n");
							//printf("saindo: ");
							//print_pilha(saindo);
							//printf("\n");
							//printf("estacao: ");
							//print_pilha(estacao);
							//printf("\n");
							//printf("\n");
						}
					}
					
				}
				
			}
			if(!stop){
				(pos ? printf("Yes") : printf("No"));
			}
			printf("\n");

			//prepara para proxima ordem desejada
			libera_pilha(saindo);
			libera_pilha(estacao);
			libera_pilha(chegando);
		}

		//prepara para proximo caso teste
		scanf(" %d", &n);
		if(n) stop=0;
	}
	printf("\n");
}
