#include "stdio.h"
#include "stdlib.h"

void printOpcoes(void);

enum pessoas{aluno, professor};

typedef struct pessoa{
    int tipo;
    void* info;
    struct pessoa* prox;
}Pessoa;

typedef struct{
    int matr;
    char nome[50];
    float salario;
}Professor;

typedef struct{
    int matr;
    char nome[50];
    char curso[50];
    int ingresso;
}Aluno;

Pessoa* listaInserir(Pessoa* p, void* m, int tipo){
    Pessoa* t = (Pessoa *) malloc(sizeof(Pessoa));
    t->tipo = tipo;
    t->info = m;

    if(p == NULL){
        t->prox = NULL;
    }
    else{
        t->prox = p;
    }

    return t;
}

Pessoa* listaRemover(Pessoa* p, int matr){
    if(p != NULL){
        Pessoa* t = p;
        Pessoa* aux = NULL;

        while(t!=NULL){
            if(aux != NULL){
                switch (t->tipo){
                    case professor:{
                        Professor* prof = (Professor *) t->info;
                        if (prof->matr == matr){
                            aux->prox = t->prox;
                            free(t);
                        }
                        break;
                    }
                    case aluno:{
                        Aluno* alun = (Aluno *) t->info;
                        if (alun->matr == matr){
                            aux->prox = t->prox;
                            free(t);
                        }
                        break;
                    }
                }
            }
            else{
                switch (t->tipo){
                    case professor:{
                        Professor* prof = (Professor *) t->info;
                        if (prof->matr == matr){
                            aux->prox = t->prox;
                            free(t);
                        }
                        break;
                    }
                    case aluno:{
                        Aluno* alun = (Aluno *) t->info;
                        if (alun->matr == matr){
                            aux->prox = t->prox;
                            free(t);
                        }
                        break;
                    }
                }
                
            }
        }
    }

}

void main(){
    int choice;
    while(1){
        printOpcoes();
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                exit(0);
            }
            default:
                break;
        }
    }
}

void printOpcoes(){
    printf("1- Inserir uma pessoa na lista (pode ser no inicio)\n");
    printf("2- Remover uma pessoa pela matricula\n");
    printf("3- Buscar uma pessoa pela matricula (caso encontre, imprimir seus dados)\n");
    printf("4- Contar o numero de alunos de um determinado curso\n");
    printf("5- Imprimir os professores de maior salario\n");
    printf("6- Sair\n");
}