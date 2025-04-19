#include "stdio.h"
#include "stdlib.h"

#define N 11

void printOpcoes(){
    printf("1- Inserir um novo aluno (matricula, nome, curso)\n");
    printf("2- Imprimir as informacoes de um determinado aluno\n");
    printf("3- Imprimir a tabela de dispersao\n");
    printf("4- Sair\n");
}

typedef struct Registro{
    char nome[50];
    char curso[50];
    int matr;
    int disponibilidade;
} registro;

void inicializar(char *nomeArq){
    FILE *arq = fopen(nomeArq, "wb");
    registro a;
    a.disponibilidade = 1;
    for (int i=0; i<N; i++)
        fwrite(&a, sizeof(registro), 1, arq);
    fclose(arq);
}

int hash(int x){
    return x%N;
}

int AcharPosicao(char *nomeArq, int x){
    int pos = hash(x);
    registro a;
    FILE *arq = fopen(nomeArq, "rb");
    fseek(arq, pos*sizeof(registro), SEEK_SET);
    fread(&a, sizeof(registro), 1, arq);
    while(a.disponibilidade == 0){
        pos = (pos+1)%N;
        fseek(arq, pos*sizeof(registro), SEEK_SET);
        fread(&a, sizeof(registro), 1, arq);
    }
    fclose(arq);
    return pos;
}

void printContent(registro a){
    if(a.disponibilidade == 0){
        printf("Matricula: %d\n", a.matr);
        printf("Nome: %s\n", a.nome);
        printf("Curso: %s\n", a.curso);
        printf("\n");
    }
    else{
        printf("Vazio.\n\n");
    }
}

void printHash(char *nomeArq){
    FILE *arq = fopen(nomeArq, "rb");
    registro a;
    for(int i=0; i<N; i++){
        fseek(arq, i*sizeof(registro), SEEK_SET);
        fread(&a, sizeof(registro), 1, arq);
        printContent(a);
    }
}

void printAluno(char *nomeArq, int matr){
    FILE *arq = fopen(nomeArq, "rb");
    int pos = AcharPosicao(nomeArq, matr);
    registro a;
    fseek(arq, pos*sizeof(registro), SEEK_SET);
    fread(&a, sizeof(registro), 1, arq);
    while(a.matr != matr){
        pos = (pos+1)%N;
        fseek(arq, pos*sizeof(registro), SEEK_SET);
        fread(&a, sizeof(registro), 1, arq);
    }
    printContent(a);
}

void mystrcpy(char *src, char *dest){
    int i=0;
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
}

void inserir(char *nomeArq, int x, char* nomeAluno, char* curso){
    int pos = AcharPosicao(nomeArq, x);
    FILE *arq = fopen(nomeArq, "r+b");
    registro a;
    mystrcpy(nomeAluno, a.nome);
    mystrcpy(curso, a.curso);

    a.matr = x;
    a.disponibilidade = 0;

    fseek(arq, pos*sizeof(registro), SEEK_SET);
    fwrite(&a, sizeof(registro), 1, arq);
    fclose(arq);
}

int main(){
    int escolha;
    char nomeArqSaida[] = "hash_data";
    inicializar(nomeArqSaida);
    while(1){
        printOpcoes();
        scanf("%d", &escolha);
        switch (escolha){
            case 1:{
                char nome[50];
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]s\n", nome);
                char curso[20];
                printf("Digite o curso do aluno: ");
                scanf(" %[^\n]s\n", curso);
                int matricula;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("\n");
                inserir(nomeArqSaida, matricula, nome, curso);
            }
            break;
            case 2:{
                int matricula;
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                printf("\n");
                printAluno(nomeArqSaida, matricula);
            }
            break;
            case 3:{
                printf("\n");
                printHash(nomeArqSaida);
            }
            break;
            case 4:{
                exit(0);
            }
            break;
        }
    }
}