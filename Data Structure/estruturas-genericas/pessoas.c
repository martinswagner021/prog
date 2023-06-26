#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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
            switch (t->tipo){
                case professor:{
                    Professor* prof = (Professor *) t->info;
                    if (prof->matr == matr){
                        if (aux != NULL){
                            aux->prox = t->prox;
                        }
                        else p = t->prox;
                        free(t);
                        return p;
                    }
                    break;
                }
                case aluno:{
                    Aluno* alun = (Aluno *) t->info;
                    if (alun->matr == matr){
                        if (aux != NULL){
                            aux->prox = t->prox;
                        }
                        else p = t->prox;
                        free(t);
                        return p;
                    }
                    break;
                }
            }
            aux = t;
            t = t->prox;
        }
    }
    return p;
}

void printPessoas(Pessoa* p){
    Pessoa* t = p;
    if(t == NULL){
        printf("Lista vazia.\n");
    }
    while(t != NULL){
        switch (t->tipo){
            case professor:{
                Professor* prof = (Professor *) t->info;
                printf("Matricula: %d\n", prof->matr);
                printf("Nome: %s\n", prof->nome);
                break;
            }
            case aluno:{
                Aluno* alun = (Aluno *) t->info;
                printf("Matricula: %d\n", alun->matr);
                printf("Nome: %s\n", alun->nome);
                break;
            }
            printf("\n");
        }
        t = t->prox;
    }
}

int listaBuscar(Pessoa* p, int matr){
    Pessoa* t = p;
    if(t == NULL){
        printf("Lista vazia.\n");
    }
    while(t != NULL){
        if (t->tipo == professor){
            Professor* prof = (Professor *) t->info;
            if (prof->matr == matr){
                printf("Matricula: %d\n", prof->matr);
                printf("Nome: %s\n", prof->nome);
                printf("Salario: %.2f\n", prof->salario);
                return 1;
            }
        }
        if (t->tipo == aluno){
            Aluno* alun = (Aluno *) t->info;
            if (alun->matr == matr){
                printf("Matricula: %d\n", alun->matr);
                printf("Nome: %s\n", alun->nome);
                printf("Curso: %s\n", alun->curso);
                printf("Ano de ingresso: %d\n", alun->ingresso);
                return 1;
            }
        }
        t = t->prox;
    }
    printf("Matricula nao encontrada.\n");
    return 0;
}

int countCurso(Pessoa* p, char* curso){
    if(p != NULL){
        if (p->tipo == aluno){
            Aluno* alun = (Aluno *) p->info;
            if (!strcmp(alun->curso, curso)) return 1 + countCurso(p->prox, curso);
        }
        return countCurso(p->prox, curso);
    }
    return 0;
}

int profMaiorSalario(Pessoa *p){
    Pessoa *t = p;
    float maiorSalario = 0;

    while(t != NULL){
        if (p->tipo == professor){
            Professor* prof = (Professor *) t->info;
            if (prof->salario > maiorSalario) maiorSalario = prof->salario;
        }
        t = t->prox;
    }

    t = p;
    while(t != NULL){
        if (p->tipo == professor){
            Professor* prof = (Professor *) t->info;
            if (prof->salario == maiorSalario) listaBuscar(p, prof->matr);
        }

        t = t->prox;
    }
}

void listaDestruir(Pessoa* p){
    for (Pessoa* t = p; t != NULL; t = t->prox){
        free(t->info);
    }
    Pessoa* aux;
    while(p != NULL){
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void main(){
    Pessoa* Lista = NULL;

    int choice;
    while(1){
        printOpcoes();
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                int choiceAlunProf;
                printf("Digite 0 para inserir Aluno\nDigite 1 para inserir Professor\n");
                scanf("%d", &choiceAlunProf);
                switch (choiceAlunProf){
                    case professor:{
                        Professor* prof = (Professor *) malloc(sizeof(Professor));
                        printf("Digite a matricula: ");
                        int matr;
                        scanf("%d", &matr);
                        prof->matr = matr;

                        printf("Digite o nome: ");
                        char nome[50];
                        scanf(" %[^\n]s", prof->nome);

                        printf("Digite o salario: ");
                        float salario;
                        scanf("%f", &salario);
                        prof->salario = salario;

                        Lista = listaInserir(Lista, prof, choiceAlunProf);
                        break;
                    }
                    case aluno:{
                        Aluno* alun = (Aluno *) malloc(sizeof(Aluno));
                        printf("Digite a matricula: ");
                        int matr;
                        scanf("%d", &matr);
                        alun->matr = matr;

                        printf("Digite o nome: ");
                        char nome[50];
                        scanf(" %[^\n]s", alun->nome);

                        printf("Digite o curso: ");
                        char curso[50];
                        scanf(" %[^\n]s", alun->curso);

                        // alun->curso;
                        // alun->ingresso;
                        printf("Digite o ingresso: ");
                        int ingresso;
                        scanf("%d", &ingresso);
                        alun->ingresso = ingresso;

                        Lista = listaInserir(Lista, alun, choiceAlunProf);
                        break;
                    }
                }
                break;
            }
            case 2:{
                printf("Digite a matricula a remover: ");
                int matr;
                scanf("%d", &matr);
                Lista = listaRemover(Lista, matr);
                break;
            }
            case 3:{
                printf("Digite a matricula a buscar: ");
                int matr;
                scanf("%d", &matr);
                listaBuscar(Lista, matr);
                break;
            }
            case 4:{
                printf("Digite o curso a contar: ");
                char curso[50];
                scanf(" %[^\n]s", curso);
                printf("O curso %s, possui %d alunos.\n", curso, countCurso(Lista, curso));

                break;
            }
            case 5:{
                profMaiorSalario(Lista);
                break;
            }
            case 6:{
                listaDestruir(Lista);
                exit(0);
            }
            default:
                break;
        }
    }
}

void printOpcoes(){
    
    printf("\n");
    printf("1- Inserir uma pessoa na lista (pode ser no inicio)\n");
    printf("2- Remover uma pessoa pela matricula\n");
    printf("3- Buscar uma pessoa pela matricula (caso encontre, imprimir seus dados)\n");
    printf("4- Contar o numero de alunos de um determinado curso\n");
    printf("5- Imprimir os professores de maior salario\n");
    printf("6- Sair\n");
}