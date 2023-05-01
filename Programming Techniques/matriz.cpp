#include<iostream>
#include<stdlib.h>

using namespace std;

float **criaMatriz(int m, int n){
    float **p;
    p = (float**) malloc(m*sizeof(float*));
    for(int i=0; i<m; i++){
        p[i] = (float*) malloc(n*sizeof(float));
    }
    return p;
}

float **somaMatriz(float **parcela1, float **parcela2, int m, int n){
    float **p = criaMatriz(m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            p[i][j] = parcela1[i][j] + parcela2[i][j];
        }
    }
    return p;
}

float prodlincol(float* v1, float* v2, int n, int j){
        float* p = (float*) malloc(n*sizeof(float));
        for(int i=0; i<n; i++){
            p[i] = v1[i]*v2[j];
        }
        float soma = 0;
        for(int i=0; i<n; i++){
            soma += p[i];
        }
        return soma;
    }

float **multMatriz(float **parcela1, float **parcela2, int m, int n){
    float **p = criaMatriz(m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            float *temp = (float*) malloc(m*sizeof(float));
            for(int k=0; k<m; k++){
                temp[k] = parcela2[j][k];
            }
            p[i][j] = prodlincol(parcela1[i],temp, m, j);
        }
    }
    return p;
}

float **potMatriz(float **M, int pot, int m, int n){
    float **p = M;
    for(int i=1; i<pot; i++){
        p = multMatriz(p, M, m, n);
    }
    return p;
}

void liberaMatriz(float **M, int m, int n){
    for(int i=0; i<m; i++){
        free(M[i]);
    }
    free(M);
}

void printMatriz(float **M, int m, int n){
    for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
}

int main(){
    float** M1 = criaMatriz(3,3);
    float** M2 = criaMatriz(3,3);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            M1[i][j]=i+1;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            M2[i][j]=j+1;
        }
    }

    printMatriz(M1, 3, 3);
    printMatriz(M2, 3, 3);
    //liberaMatriz(M2, 3, 3);
    printMatriz(somaMatriz(M1, M2, 3, 3), 3, 3);
    printMatriz(multMatriz(M1, M1, 3, 3), 3, 3);
    printMatriz(potMatriz(M1, 3, 3, 3), 3, 3);
}