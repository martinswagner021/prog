#include "stdio.h"
#include "stdlib.h"
#include "avl.h"
#include "string.h"

enum teorica_pratica {teorica, pratica};

typedef struct{
    int duda;
    char cpf[12];
    char nome[50];
    int teorica_pratica;
} aluno;

void printMenu(){
    printf("1- Inserir um aluno.\n");
    printf("2- Consultar duda pago.\n");
    printf("3- Consultar os dados de um aluno.\n");
    printf("4- Alterar andamento.\n");
    printf("5- Remover um aluno.\n");
    printf("6- Imprimir todos os alunos.\n");
    printf("7- Sair.\n");
}

int main(){
    avl autoescola = avl_inicializar();
    int contador_ordem = 1;
    int opt;
    while(1){
        printMenu();
        scanf("%d", &opt);
        switch (opt){
            case 1:{
                aluno* a = (aluno *) malloc(sizeof(aluno));
                printf("Insira duda:\n");
                scanf("%d", &(a->duda));
                printf("Insira o cpf:\n");
                scanf(" %[^\n]", a->cpf);
                printf("Insira o nome:\n");
                scanf(" %[^\n]", a->nome);
                a->teorica_pratica = teorica;
                autoescola = inserir(autoescola, a->duda, a, sizeof(aluno));
                free(a);
                break;
            }
            case 2:{
                printf("Digite o duda a ser consultado: ");
                int duda;
                scanf("%d", &duda);
                existe(autoescola, duda) ? printf("Duda cadastrado.\n") : printf("Duda nao cadastrado.\n");
                break;
            }
            case 3:{
                printf("Digite o duda a ser consultado: ");
                int duda;
                scanf("%d", &duda);
                aluno* a = malloc(sizeof(aluno));
                duda = buscar(autoescola, duda, a, sizeof(aluno));
                if(duda){
                    printf("Duda %d encontrado.\n", duda);
                    printf("Aluno(a): %s\n", a->nome);
                    printf("CPF: %s\n", a->cpf);
                    if(a->teorica_pratica == teorica) printf("Situacao: Teorica.\n");
                    else printf("Situacao: Pratica.\n");
                }
                else{
                    printf("Duda nao encontrado.\n");
                }
                free(a);
                break;
            }
            case 4:{
                printf("Digite o duda do aluno: ");
                int duda;
                scanf("%d", &duda);
                aluno* a = malloc(sizeof(aluno));
                duda = buscar(autoescola, duda, a, sizeof(aluno));
                if(a->teorica_pratica == teorica){
                    a->teorica_pratica = !a->teorica_pratica;
                    autoescola = remover(autoescola, duda);
                    autoescola = inserir(autoescola, duda, a, sizeof(aluno));
                }
                else{
                    printf("Aluno ja concluiu teorica.");
                }
                free(a);
                break;
            }
            case 5:{
                printf("Digite o duda do aluno: ");
                int duda;
                scanf("%d", &duda);
                autoescola = remover(autoescola, duda);
            }
            case 6:{
                imprimir(autoescola);
                break;
            }
            case 7:{
                autoescola = avl_destruir(autoescola);
                exit(0);
            }
            default:
                break;
            }
    }
}