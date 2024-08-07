#ifndef FILA_H
#define FILA_H

typedef struct Fila *fila;
// Inicializa e retorna uma fila vazia com espaco para 100 inteiros
fila filaInicializar(void);
// Insere um elemento no final da fila
void filaInserir(fila p, int info);
// Imprime todos os elementos da fila
void filaImprimir(fila p);
// Retorna o elemento removido (-1 se a fila estiver vazia)
int filaRemover(fila p);
// Retorna 1 ou 0, Vazia ou nao
int filaIsVazia(fila p);
// Destroi todos os elementos da fila
void filaDestruir(fila p);

#endif