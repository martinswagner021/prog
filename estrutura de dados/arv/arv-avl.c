// Autor: Wagner Martins
// Disciplina: Estrutura de Dados
// Atividade 3 - Arvore AVL

#include<stdio.h>
#include<stdlib.h>

// Forma curta de informar as opcoes para o usuario
void printOpcoes(){
    printf("1- Ler uma arvore de um arquivo fornecido pelo usuario\n");
    printf("2- Imprimir a arvore (pre-ordem; em-ordem; pos-ordem; em largura)\n");
    printf("3- Verificar se um elemento x existe na arvore\n");
    printf("4- Imprimir o nivel de um no x\n");
    printf("5- Imprimir as folhas menores que um valor x\n");
    printf("6- Inserir um no x na arvore\n");
    printf("7- Remover um no x da arvore\n");
    printf("8- Sair\n");
}

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}arv;

typedef struct avl{
    int info;
    int FB;
    struct avl *esq;
    struct avl *dir;
}avl;

avl *LerArv(FILE *arq){
    char c;
    int num;

    fscanf(arq, "%c", &c);
    fscanf(arq, "%d", &num);

    if(num == -1){
        fscanf(arq, "%c", &c);
        return NULL;
    }
    else{
        avl *a;
        a = (avl*) malloc(sizeof(avl));
        a->info = num;
        a->esq = LerArv(arq);
        a->dir = LerArv(arq);
        fscanf(arq, "%c", &c);
        return a;
    }
}

// Funcoes matematicas para calculo de altura e balanceamento
int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int alturaArv(avl* a){
    if(a!=NULL){
        return 1+max(alturaArv(a->esq), alturaArv(a->dir));
    }
    return 0;
}

void ajustarFB(avl* a){
    if(a!=NULL){
        int he = alturaArv(a->esq);
        int hd = alturaArv(a->dir);
        a->FB = hd-he;

        ajustarFB(a->esq);
        ajustarFB(a->dir);
    }
}

avl *LerAVL(FILE *arq){
    avl *a = LerArv(arq);
    ajustarFB(a);
    return a;
}

avl* findElem(avl* a, int x){
    if(a!=NULL){
        if(x == a->info) return a;
        if(x < a->info) return findElem(a->esq, x);
        if(x > a->info) return findElem(a->dir, x);
    }
    return NULL;
}

int existeX(avl* a, int x){
    avl* y = findElem(a, x);
    if(y==NULL) return 0;
    return 1;
}

// Ao chamar a funcao, certifique-se de que nivel = 0
int nivelNoX(avl* a, int x, int nivel){
    if(a!=NULL){
        if(a->info==x) return nivel;
        if(x<a->info) return nivelNoX(a->esq, x, nivel+1);
        if(x>a->info) return nivelNoX(a->dir, x, nivel+1);
    }
    return -1;
}


// Metodos de print
void printArvPreOrdem(avl* a){
    if(a!=NULL){
        printf("%d\n", a->info);
        printArvPreOrdem(a->esq);
        printArvPreOrdem(a->dir);
    }
}
void printArvEmOrdem(avl* a){
    if(a!=NULL){
        printArvEmOrdem(a->esq);
        printf("%d\n", a->info);
        printArvEmOrdem(a->dir);
    }
}
void printArvPosOrdem(avl* a){
    if(a!=NULL){
        printArvPosOrdem(a->esq);
        printArvPosOrdem(a->dir);
        printf("%d\n", a->info);
    }
}

// Estrutura de fila pra impressao em largura
typedef struct lista{
    avl* info;
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

void insereFila(fila* p, avl *x){
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
    avl* v = t->info;

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

void printArvEmLargura(avl* a){
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

void printFolha(avl* a){
    if(a!=NULL){
        printFolha(a->esq);
        printFolha(a->dir);
        if(a->dir == NULL && a->esq == NULL) printf("%d\n", a->info);
    }
}

// TODO: Correct this function
void printFolhasMenores(avl* a, int x){
    if(a!=NULL){
        if(x == a->info){
            printFolha(a->esq);
        }
        if(x > a->info){
            printFolha(a->esq);
            printFolha(a->dir);
        }
        if(x < a->info){
            printFolhasMenores(a->esq, x);
        }
    }
}

avl* rot_dir_simples(avl* x){
    avl* y = x->esq;
    x->esq = y->dir;
    y->dir = x;
    
    return y;
}

avl* rot_esq_simples(avl* x){
    avl* y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    
    return y;
}

avl* rot_dir(avl* x){
    avl *y = x->esq;
    if(alturaArv(y->dir) > alturaArv(y->esq)){
        x->esq = rot_esq_simples(y);
        return rot_dir_simples(x);
    }
    else{
        return rot_dir_simples(x);
    }
}

avl* rot_esq(avl* x){
    avl *y = x->dir;
    if(alturaArv(y->esq) > alturaArv(y->dir)){
        x->dir = rot_dir_simples(y);
        return rot_esq_simples(x);
    }
    else{
        return rot_esq_simples(x);
    }
}

avl* inserirArv(avl* a, int x){
    if(a==NULL){
        a = (avl*) malloc(sizeof(avl));
        a->info = x;
        a->FB = 0;
        a->esq = NULL;
        a->dir = NULL;
    }
    if(x < a->info) a->esq = inserirArv(a->esq, x);
    if(x > a->info) a->dir = inserirArv(a->dir, x);

    ajustarFB(a);
    if(!(a->FB >= -1 && a->FB<=1)){
        // Esta desbalanceada na direita
        if(a->FB > 0){
            // rotacionar a esq
            return rot_esq(a);
        }
        // Esta desbalanceada na esquerda
        if(a->FB < 0){
            // rotacionar a dir
            return rot_dir(a);
        }
    }
    return a;
}

// Retorna a avlore com o elemento removido
avl* removerArv(avl* a, int x){
    if(a!=NULL){
        if(a->info==x){
            if(a->esq==NULL && a->dir==NULL){
                free(a);
                return NULL;
            }
            if(a->esq==NULL){
                avl* aux = a->dir;
                free(a);
                return aux;
            }
            if(a->dir==NULL){
                avl* aux = a->esq;
                free(a);
                return aux;
            }
            avl* aux = a->esq;
            while(aux->dir!=NULL) aux = aux->dir;
            a->info = aux->info;
            a->esq = removerArv(a->esq, aux->info);
        }
        if(x<a->info) a->esq = removerArv(a->esq, x);
        if(x>a->info) a->dir = removerArv(a->dir, x);

        ajustarFB(a);
        if(!(a->FB >= -1 && a->FB<=1)){
            // Esta desbalanceada na direita
            if(a->FB > 0){
                // rotacionar a esq
                return rot_esq(a);
            }
            // Esta desbalanceada na esquerda
            if(a->FB < 0){
                // rotacionar a dir
                return rot_dir(a);
            }
        }
    }
    return a;
}

avl* liberaArv(avl* a){
    if(a!=NULL){
        liberaArv(a->esq);
        liberaArv(a->dir);
        free(a);
    }
    return NULL;
}

int main() {

    int selection;
    avl* uArv = NULL;
    FILE* uArq = NULL;
    int elem;
    
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
            uArv = LerAVL(uArq);

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
                    printf("Essa opcao nao esta disponivel!\n");
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

            printf("Digite o elemento x desejado:\n");
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

            printf("Digite o elemento x desejado:\n");
            scanf("%d", &elem);
            int n = nivelNoX(uArv, elem, 0);

            n==-1 ? printf("O elemento nao existe.\n") : printf("Seu nivel e: %d\n", n);

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

            printf("Digite o elemento x desejado:\n");
            scanf("%d", &elem);
            printFolhasMenores(uArv, elem);

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

            printf("Digite o elemento x desejado:\n");
            scanf("%d", &elem);
            uArv = inserirArv(uArv, elem);

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

            printf("Digite o elemento x desejado:\n");
            scanf("%d", &elem);
            uArv = removerArv(uArv, elem);

            printOpcoes();
            scanf("%d",&selection);
            break;

        case 8:
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