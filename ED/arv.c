// Autor: Wagner Martins
// Disciplina: Estrutura de Dados
// Atividade 1 - Arvore Binaria

#include<stdio.h>

// Forma curta de informar as opcoes para o usuario
void printOpcoes(){
    printf("1- Ler uma arvore de um arquivo fornecido pelo usuario\n");
    printf("2- Imprimir a arvore (pre-ordem; em-ordem; pos-ordem; em largura)\n");
    printf("3- Verificar se um elemento x existe na arvore\n");
    printf("4- Contar o numero de elementos da arvore\n");
    printf("5- Imprimir os nos folhas da arvore\n");
    printf("6- Verificar se uma arvore esta balanceada\n");
    printf("7- Verificar se uma arvore esta cheia\n");
    printf("8- Imprimir o nivel de um no x\n");
    printf("9- Sair\n");
}

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}arv;

arv *LerArv(FILE *arq){
    char c;
    int num;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if(num == -1){
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else{
        arv *a;
        a = (arv*) malloc(sizeof(arv));
        a->info = num;
        a->esq = LerArv(arq);
        a->dir = LerArv(arq);
        fscanf(arq, "%c", &c);
        return a;
    }
}

int existeX(arv* a, int x){
    if(a!=NULL){
        if(a->info == x) return 1;
        if(existeX(a->esq, x) || existeX(a->dir, x)) return 1;
        return 0;
    }
    return 0;
}

int numElemArv(arv* a){
    if(a!=NULL){
        return 1 + numElemArv(a->esq) + numElemArv(a->dir);
    }
    return 0;
}

void printFolha(arv* a){
    if(a!=NULL){
        printFolha(a->esq);
        printFolha(a->dir);
        if(a->dir == NULL && a->esq == NULL) printf("%d\n", a->info);
    }
}

int nivelNoX(arv* a, int x){
    if(a!=NULL){
        if(a->info==x) return 0;

        int e,d;
        e = nivelNoX(a->esq, x);
        d = nivelNoX(a->dir, x);
        if(e!=-1) return 1+e;
        if(d!=-1) return 1+d;
        return -1;
    }
    return -1;
}

// Funcoes matematicas para calculo de altura e balanceamento
int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int pow2(int n){
    int pow=1;
    for(int i=0; i<n; i++) pow *= 2;
    return pow;
}

int alturaArv(arv* a){
    if(a!=NULL){
        return 1+max(alturaArv(a->esq), alturaArv(a->dir));
    }
    return 0;
}

int isBalanceada(arv* a){
    if(a!=NULL){
        int he = alturaArv(a->esq);
        int hd = alturaArv(a->dir);
        if(he-hd>=-1 && he-hd<=1) return 1;
        return 0;
    }
    return 1;
}

int isCheia(arv *a){
    if(pow2(alturaArv(a))-1 == numElemArv(a)) return 1;
    return 0;
}

// Metodos de print
void printArvPreOrdem(arv* a){
    if(a!=NULL){
        printf("%d\n", a->info);
        printArvPreOrdem(a->esq);
        printArvPreOrdem(a->dir);
    }
}
void printArvEmOrdem(arv* a){
    if(a!=NULL){
        printArvEmOrdem(a->esq);
        printf("%d\n", a->info);
        printArvEmOrdem(a->dir);
    }
}
void printArvPosOrdem(arv* a){
    if(a!=NULL){
        printArvPosOrdem(a->esq);
        printArvPosOrdem(a->dir);
        printf("%d\n", a->info);
    }
}

// Estrutura de fila pra impressao em largura
typedef struct lista{
    arv* info;
    struct lista* prox;
}lista;

typedef struct fila{
    struct lista* ini;
    struct lista* fim;
}fila;

fila* criaFila(){
    fila* p = (fila*) malloc(sizeof(fila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}

void insereFila(fila* p, arv *x){
    lista* t = (lista*) malloc(sizeof(lista));
    t->info = x;
    t->prox = NULL;

    if(p->fim!=NULL) p->fim->prox = t;
    else p->ini = p->fim = t;

    p->fim = t;
}

int removeFila(fila* p){
    if(p->ini==NULL) return -1;

    lista* t = p->ini;
    arv* v = t->info;

    p->ini = t->prox;
    if(p->ini == NULL) p->fim = NULL;
    free(t);
    return v->info;
}

void liberaFila(fila* p){
    lista* t = p->ini;
    while(t!=NULL){
        lista* l = t->prox;
        free(t);
        t=l;
    }
    free(p);
}

void printArvEmLargura(arv* a){
    if(a!=NULL){
        fila* f = criaFila();
        insereFila(f, a);
        while(f->ini!=NULL){
            a = f->ini->info;
            printf("%d\n", removeFila(f));
            if(a->esq!=NULL) insereFila(f, a->esq);
            if(a->dir!=NULL) insereFila(f, a->dir);
        }
        liberaFila(f);
    }
}

arv* liberaArv(arv* a){
    if(a!=NULL){
        liberaArv(a->esq);
        liberaArv(a->dir);
        free(a);
    }
    return NULL;
}

int main() {

    int selection;
    arv* uArv = NULL;
    FILE* uArq = NULL;
    
    printOpcoes();
    scanf("%d",&selection);

    while(1){
        switch (selection)
        {
        case 1:
            if(uArq!=NULL){
                fclose(uArq);
                uArv = liberaArv(uArv);
            }
            char nomedoarquivo[99];
            printf("Digite o nome do arquivo (Certifique-se que esteja na mesma pasta):\n");
            scanf("%s", nomedoarquivo);
            uArq = fopen(nomedoarquivo, "rt");
            if(uArq == NULL){
                printf("Erro na leitura do arquivo.\n");
                exit(1);
            }
            uArv = LerArv(uArq);

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 2:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            int ordem;
            printf("1- pre-ordem\n2- em-ordem\n3- pos-ordem\n4- em largura\n");
            scanf("%d", &ordem);
            printf("Os elementos da arvore sao:\n");
            switch (ordem)
            {
            case 1:
                printArvPreOrdem(uArv);
                break;
            case 2:
                printArvEmOrdem(uArv);
                break;
            case 3:
                printArvPosOrdem(uArv);
                break;
            case 4:
                printArvEmLargura(uArv);
                break;
            default:
                break;
            }

            printOpcoes();
            scanf("%d",&selection);
            break;
        case 3:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            int elem;
            printf("Insira o valor a ser verificado:\n");
            scanf("%d", &elem);

            existeX(uArv, elem) ? printf("Este elemento existe.\n") : printf("Este elemento nao existe.\n");

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 4:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            printf("A arvore possui %d elementos.\n", numElemArv(uArv));

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 5:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            printf("As folhas sao:\n");
            printFolha(uArv);

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 6:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            isBalanceada(uArv) ? printf("A arvore esta balanceada.\n") : printf("A arvore esta desbalanceada.\n");

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 7:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            isCheia(uArv) ? printf("A arvore e cheia.\n") : printf("A arvore nao e cheia.\n");

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 8:
            // Verificar existencia de uma arvore
            if(uArq==NULL){
                printf("Carregue uma arvore primeiro.\n");
                printOpcoes();
                scanf("%d", &selection);
                break;
            }

            int no;
            printf("Insira o no desejado para obter seu nivel:\n");
            scanf("%d", &no);

            int nivelno = nivelNoX(uArv, no);
            
            if(nivelno == -1) printf("O no nao foi encontrado.\n");
            else printf("O nivel do no desejado e: %d\n", nivelno);

            printOpcoes();
            scanf("%d",&selection);
            break;
            
        case 9:
            if(uArq!=NULL){
                fclose(uArq);
                uArv = liberaArv(uArv);
            }
            return 0;
            break;

        default:
            printf("%d nao e uma opcao valida.\n", selection);

            printOpcoes();
            scanf("%d", &selection);
            break;
        }
    }
}