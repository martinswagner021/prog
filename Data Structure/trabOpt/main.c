#include "stdio.h"
#include "stdlib.h"
#include "avl.h"
#include "string.h"

typedef struct{
    int matricula;
    char nome[50];
    float nota;
} aluno;

int main(){
    avl turma = avl_inicializar();

    aluno* a = (aluno *) malloc(sizeof(aluno));
    a->matricula = 60019;
    strcpy(a->nome, "Wagner Martins");
    a->nota = 10;

    turma = inserir(turma, a->matricula, a, sizeof(aluno));

    aluno* test = (aluno *) malloc(sizeof(aluno));
    buscar(turma, 60019, test, sizeof(aluno));
    printf("%s: %.2f\n", test->nome, test->nota);
}