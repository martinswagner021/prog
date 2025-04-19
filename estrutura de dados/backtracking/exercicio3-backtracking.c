#include<stdio.h>
#include<stdlib.h>

int check_comb(int *v, int tam, int n, int pos, int *aux, int valor){
        if(pos == n){
            int soma = 0;
            for(int i=0; i<n; i++){
                soma += v[i];
            }
            if(soma == valor){
                for(int i=0; i<n; i++) printf("%d ", v[i]);
                printf("\n");
                return 1;
            }
        }
        else{
            for(int i=0; i<tam; i++){
                v[pos] = aux[i];
                if(check_comb(v, tam, n, pos+1, aux, valor) == 1) return 1;
            }
        }
}

int main(){

    int aux[] = {1, 5, 10, 25, 50};
    int tam = 5;
    int valor;
    printf("Insira o valor em centavos desejado: ");
    scanf("%d", &valor);
    int *v = (int*) malloc(valor*sizeof(int));

    for(int n=1; n<=valor; n++){
        check_comb(v, tam, n, 0, aux, valor);
    }

}