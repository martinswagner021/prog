#include "stdio.h"
#include "fila.h"

int main(){
    fila p = filaInicializar();
    filaInserir(p, 3);
    filaInserir(p, 2);
    filaInserir(p, 5);
    filaInserir(p, 23);
    filaImprimir(p);
    filaRemover(p);
    filaRemover(p);
    filaRemover(p);
    filaRemover(p);

    filaIsVazia(p) ? printf("Fila vazia.\n") : printf("Fila preenchida.\n");
    filaImprimir(p);
    filaDestruir(p);
}