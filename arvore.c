#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (a>b ? a : b)

typedef struct arv{
	int info;
	struct arv* dir;
	struct arv* esq;
}Arv;

// Para criar uma arv null, basta digitar NULL para os parametros de sae e sad
Arv* cria_arv(int info, Arv* sae, Arv* sad){
	Arv* p = (Arv*) malloc(sizeof(Arv));
	p->info = info;
	p->esq = sae;
	p->dir = sad;

	return p;
}

void print_arv_simetrica(Arv* p){
	printf("<");
	if(p != NULL){
		printf("%d", p->info);
		print_arv_simetrica(p->esq);
		print_arv_simetrica(p->dir);
	}
	printf(">");
}

int h_arv(Arv* p){
	if(p == NULL) return 0;
	if(p->esq == NULL && p->dir == NULL){
		return 0;
	}
	else{
		return 1+MAX(h_arv(p->esq),h_arv(p->dir));
	}
}

Arv* insere_binario(Arv* t, int info){
	Arv* p = (Arv*) malloc(sizeof(Arv));

	if(t == NULL){
		p->info = info;
		p->esq = NULL;
		p->dir = NULL;

		return p;
	}
	if(info <= t->info){
		t->esq = insere_binario(t->esq,info);
	}
	else{
		t->dir = insere_binario(t->dir,info);
	}

	return t;
}

// qualquer elemento que nn exista retornara a altura da folha mais proxima
int nivel_arv(Arv* p, int info){
	if(p==NULL) return 0;

	if(p->info < info){
		return 1+nivel_arv(p->dir, info);
	}
	if(p->info > info){
		return 1+nivel_arv(p->esq, info);
	}

	return 0;
}
	

int main(){

	Arv* L = NULL;

	L = insere_binario(L, 20);
	L = insere_binario(L, 10);
	L = insere_binario(L, 5);
	L = insere_binario(L, 30);
	L = insere_binario(L, 15);
	L = insere_binario(L, 13);

	print_arv_simetrica(L);
	printf("\n");

	printf("altura: %d\n",h_arv(L));
	printf("\n");
	
	printf("nivel: %d\n",nivel_arv(L,13));
	printf("\n");

}
