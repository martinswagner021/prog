#include "stdio.h"
#include "fila.h"

void printOpcoes(){
    printf("1- Inserir um elemento na fila\n");
    printf("2- Remover um elemento da fila (imprimir o elemento removido)\n");
    printf("3- Imprimir a fila\n");
    printf("4- Sair\n");
}

int main(){
    fila p = filaInicializar();
    int choice;
    while(1){
        printOpcoes();
        scanf("%d", &choice);
        switch (choice){
            case 1:{
                printf("Digite o numero a ser inserido:\n");
                int insert;
                scanf("%d", &insert);
                filaInserir(p, insert);
                break;
            }
            case 2:{
                int elem = filaRemover(p);
                (elem == -1) ? printf("Impossivel remover de uma fila vazia\n") : printf("O elemento removido foi: %d\n", elem);
                break;
            }
            case 3:{
                filaImprimir(p);
                break;
            }
            case 4:{
                filaDestruir(p);
                return(0);
            }
            default:
                break;
        }
    }
}