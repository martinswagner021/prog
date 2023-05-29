#include<stdio.h>
#include<stdlib.h>

void printOpcoes(){
    printf("1- Inserir uma aresta no grafo\n");
    printf("2- Remover uma aresta do grafo\n");
    printf("3- Imprimir o grafo\n");
    printf("4- Imprimir os graus de entrada e saida de um vertice\n");
    printf("5- Verificar se um grafo e completo\n");
    printf("6- Imprimir todos os caminhos entre uma origem e um destino\n");
    printf("7- Imprimir o caminho mais curto (com menor numero de arestas)\n");
    printf("8- Imprimir o caminho de menor custo (menor soma dos custos das arestas)\n");
    printf("9- Sair\n");
}

typedef struct lista{
    int destino;
    int custo;
    struct lista* prox;
} lista;

lista* inserirLista(lista* l, int d, int c){
    lista* p = (lista*) malloc(sizeof(lista));
    p->destino = d;
    p->custo = c;
    p->prox = l;

    return p;
}
lista* removerLista(lista* l, int d){
    lista* p = l;
    lista* aux = NULL;
    while(p!=NULL && p->destino != d){
        aux=p;
        p=p->prox;
    }
    if(p == NULL) return l;
    
    if(aux==NULL) l = p->prox;
    else aux->prox = p->prox;

    free(p);
    return l;
}

lista** inicializarGrafo(lista** g, int n){
    g = (lista**) malloc((n+1)*sizeof(lista*));
    for(int i=0; i<n; i++){
        g[i]=NULL;
    }
    return g;
}

void inserirAresta(lista** g, int o, int d, int c){
    g[o] = inserirLista(g[o], d, c);
}
void removerAresta(lista** g, int o, int d){
    g[o] = removerLista(g[o], d);
}

void printGrafo(lista** g, int n){
    for(int i=1; i<=n; i++){
        printf("vertice %d: ", i);
        for(lista* p=g[i]; p != NULL; p = p->prox) printf("(%d, %d) ", p->destino, p->custo);
        printf("\n");
    }
}

void printGrauSaida(lista** g, int v){
    int count = 0;
    for(lista* p=g[v]; p != NULL; p = p->prox) count++;
    printf("Grau de saida do vertice: %d\n", count);
}

void printGrauEntrada(lista** g, int n, int v){
    int count = 0;
    for(int i=1; i<=n; i++){
        for(lista* p=g[i]; p != NULL; p = p->prox) p->destino == v ? count++ : count;
    }
    printf("Grau de entrada do vertice: %d\n", count);
}

int isCompleto(lista** g, int n){
    int count = 0;
    for(int i=1; i<=n; i++){
        for(lista* p=g[i]; p != NULL; p = p->prox) count++;
    }
    return count == n*(n-1);
}

void printTodosCaminhos(lista** g, int d, int* aux, int pos){
    if(aux[pos-1] == d){
        for(int i=0; i<pos; i++){
            printf("%d ", aux[i]);
        }
        printf("\n");
    }
    else{
        lista* p = g[aux[pos-1]];
        while(p != NULL){
            aux[pos] = p->destino;
            printTodosCaminhos(g, d, aux, pos+1);
            p = p->prox;
        }
    }
}

void printMenorCusto(lista** g, int d, int* aux, int pos, int custo, int* Mcaminho){
    if(aux[pos-1] == d){
        if(custo < Mcaminho[0]){
            printf("Novo vetor menor que antigo!\n");
            printf("Custo: %d\n", custo);
            Mcaminho[1] = pos;
            printf("Tamanho do novo vetor: %d\n", Mcaminho[1]);
            for(int i=0; i<pos; i++) Mcaminho[i+2] = aux[i];
        }
    }
    else{
        lista* p = g[aux[pos-1]];
        while(p != NULL){
            aux[pos] = p->destino;
            printMenorCusto(g, d, aux, pos+1, custo+p->custo, Mcaminho);
            p = p->prox;
        }
    }
}

int main(){
    int escolha; // switch opcao
    printf("Insira o numero de vertices do grafo: ");
    int n; // qntd de vertices do projeto
    scanf("%d", &n);
    lista** g = inicializarGrafo(g, n); // grafo utilizado
    int *aux = (int*) malloc(n*sizeof(int)); // utilizado para backtracking dos vetores
    int v; // utilizado na busca de um vertice especifico

    int* Mcaminho = (int*) malloc((n+2)*sizeof(int)); // vetor para encontrar melhor caminho
    
    printOpcoes();
    scanf("%d", &escolha);
    while(1){
        int o, d, c;
        switch (escolha){
        case 1:
            printf("Digite a origem: ");
            scanf("%d", &o);
            printf("Digite o destino: ");
            scanf("%d", &d);
            printf("Digite a custo: ");
            scanf("%d", &c);
            inserirAresta(g, o, d, c);

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 2:
            printf("Digite a origem: ");
            scanf("%d", &o);
            printf("Digite o destino: ");
            scanf("%d", &d);
            removerAresta(g, o, d);

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 3:
            printGrafo(g, n);

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 4:
            printf("Insira o vertice desejado: ");
            scanf("%d", &v);
            printGrauEntrada(g, n, v);
            printGrauSaida(g, v);

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 5:
            isCompleto(g, n) ? printf("O grafo e completo.\n") : printf("O grafo nao e completo\n");

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 6:
            printf("Insira a origem: ");
            scanf("%d", &o);
            printf("Insira o destino: ");
            scanf("%d", &d);
            aux[0] = o;
            printTodosCaminhos(g, d, aux, 1);
            
            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 7:
            // mais curto
            printf("Insira a origem: ");
            scanf("%d", &o);
            printf("Insira o destino: ");
            scanf("%d", &d);
            aux[0] = o;
            printTodosCaminhos(g, d, aux, 1);

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 8:
            // menor custo
            printf("Insira a origem: ");
            scanf("%d", &o);
            printf("Insira o destino: ");
            scanf("%d", &d);
            aux[0] = o;
            Mcaminho[0] = 10000;
            printMenorCusto(g, d, aux, 1, 0, Mcaminho);
            for(int i=2; i<Mcaminho[1]+2; i++) printf("%d ", Mcaminho[i]);
            printf("\n");

            printOpcoes();
            scanf("%d", &escolha);
            break;
        case 9:
            exit(0);
            break;
        
        default:
            printf("Essa nao e uma opcao valida.\n");
            printOpcoes();
            scanf("%d", &escolha);

            break;
        }
    }
}