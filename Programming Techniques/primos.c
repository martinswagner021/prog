#include<stdio.h>
#include<stdlib.h>

#define FIM 167

int divisores(int n){
    int i=3;
    while(i<n){
        if(n%i==0) return i;
        i++;
    }
    return 0;
}

int* tabela(int n){
    int* p = (int* ) malloc(1000*sizeof(int));
    
    int j=0;
    for(int i=3; i<1000; i=i+2){
        if(divisores(i)==0){
            p[j] = i;
            j++;
        }
    }
    return p;
}

void printv(int* v){
    printf("{");
    int i;
    for(i=0; v[i]!=0; i++){
        printf("%d,", v[i]);
    }
    printf("}\n");
}

int buscaBinaria(int *v, int ini, int fim, int key){
    int med = (ini+fim)/2;
    if(fim>=ini){
        if(v[med]==key){
            return med;
        }
        if(v[med]>key){
            return buscaBinaria(v, ini, med-1, key);
        }
        if(v[med]<key){
            return buscaBinaria(v, med+1, fim, key);
        }
    }
    
    return -1;

}

int achaprimo(int *v, int n){
    // excecao numero par
    if(n==2) return 167;

    int itr = buscaBinaria(v, 0, FIM, n);
    while(itr == -1){
        n--;
        itr = buscaBinaria(v, 0, FIM, n);
    }
    return itr;
}

int main() {

    int v[] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,2};

    int n,m;
    scanf(" %d %d", &n, &m);

    printf("%d\n", v[achaprimo(v, n)]*v[achaprimo(v, m)]);
}