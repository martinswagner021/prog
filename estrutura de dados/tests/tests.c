#include "stdio.h"
#include "stdlib.h"
#define N 4

typedef struct aresta{
    int dest;
    int custo;
    struct aresta* prox;
}aresta;

typedef struct{
    int arestas[N*(N-1)];
    int custo;
}caminho;

aresta** inicializar(){
    aresta **vertices = (aresta **) malloc((N+1)*sizeof(aresta*));
    for (int i=0; i<=N; i++){
        vertices[i] = NULL;
    }
    return vertices;
}

void inserir(aresta** g, int orig, int dest, int custo){
    aresta* a = (aresta *) malloc(sizeof(aresta));
    a->custo = custo;
    a->dest = dest;
    if (g[orig] == NULL){
        g[orig] = a;
        a->prox = NULL;
    }
    else{
        a->prox = g[orig];
        g[orig] = a;
    }
}

void printGrafo(aresta** g){
    for (int i=1; i<=N; i++){
        printf("Origem: %d ==========\n", i);
        for (aresta* j=g[i]; j!=NULL; j = j->prox){
            printf("Destino: %d, Custo: %d\n", j->dest, j->custo);
        }
        printf("====================\n");
    }
}

void printMelhorCaminho(aresta** g, int orig, int dest, int* vetaux, int pos, caminho* melhor, int custo){
    if (vetaux[pos-1] == dest){
        if (custo <= melhor->custo){
            int i = 0;
            while(i<pos){
                melhor->arestas[i] = vetaux[i];
                i++;
            }
            melhor->arestas[i] = -1;
            melhor->custo = custo;
        }
    }
    else{
        if (pos == 1) vetaux[0] = orig;
        for (aresta* i=g[orig]; i != NULL; i = i->prox){
            vetaux[pos] = i->dest;
            printMelhorCaminho(g, vetaux[pos], dest, vetaux, pos + 1, melhor, custo + i->custo);
        }
    }
}

void printMelhorCaminhoEspecial(aresta** g, int orig, int dest, int* vetaux, int pos, caminho* melhor, int custo, int vertice){
    if (vetaux[pos-1] == dest){
        int passa_pelo_vertice = 0;
        for (int i = 0; i<pos; i++){
            if (vetaux[i] == vertice) passa_pelo_vertice = 1;
        }
        if (custo <= melhor->custo && passa_pelo_vertice){
            int i = 0;
            while(i<pos){
                melhor->arestas[i] = vetaux[i];
                i++;
            }
            melhor->arestas[i] = -1;
            melhor->custo = custo;
        }
    }
    else{
        if (pos == 1) vetaux[0] = orig;
        for (aresta* i=g[orig]; i != NULL; i = i->prox){
            vetaux[pos] = i->dest;
            printMelhorCaminhoEspecial(g, vetaux[pos], dest, vetaux, pos + 1, melhor, custo + i->custo, vertice);
        }
    }
}

void printTodosOsCaminhos(aresta** g, int orig, int dest, int* vetaux, int pos){
    if (vetaux[pos-1] == dest){
        for (int i=0; i<pos; i++){
            printf("%d ", vetaux[i]);
        }
        printf("\n");
    }
    else{
        if (pos == 1) vetaux[0] = orig;
        for (aresta* i=g[orig]; i != NULL; i = i->prox){
            vetaux[pos] = i->dest;
            printTodosOsCaminhos(g, vetaux[pos], dest, vetaux, pos + 1);
        }
    }
}

int main(){
    aresta** grafo = inicializar();
    inserir(grafo, 1, 2, 7);
    inserir(grafo, 1, 4, 7);
    inserir(grafo, 2, 3, 2);
    inserir(grafo, 2, 4, 7);
    inserir(grafo, 3, 4, 3);
    inserir(grafo, 4, 1, 1);

    printGrafo(grafo);

    caminho* melhor = (caminho *) malloc(sizeof(caminho));
    melhor->custo = 100000;
    printTodosOsCaminhos(grafo, 1, 1, (int *) malloc((N*(N-1))*sizeof(int)), 1);
    printMelhorCaminhoEspecial(grafo, 1, 1, (int *) malloc((N*(N-1))*sizeof(int)), 1, melhor, 0, 2);
    int i = 0;
    while (melhor->arestas[i] != -1){
        printf("%d ", melhor->arestas[i]);
        i++;
    }
    printf("\n");
}