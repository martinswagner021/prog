/*
Autor: Wagner Martins
Atividade 1 - Heap
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int* h;
    int last_elem;
} Heap;

Heap* create_heap(int heap_size) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->h = (int*)malloc(heap_size * sizeof(int));
    h->last_elem = 0;
    return h;
}

int indicePai(Heap* h, int ind) {
    int indice = (int)(ind - 1) / 2;
    if (ind <= 0 || ind >= h->last_elem) {
        return -1;
    }
    return indice;
}

int indiceFilhoEsq(Heap* h, int ind) {
    int indice = (ind * 2) + 1;
    if (indice <= 0 || indice >= h->last_elem) {
        return -1;
    }
    return indice;
}

int indiceFilhoDir(Heap* h, int ind) {
    int indice = (ind * 2) + 2;
    if (indice <= 0 || indice >= h->last_elem) {
        return -1;
    }
    return indice;
}

void ajustarSubindo(Heap* h, int pos) {
    if (pos != -1 && indicePai(h, pos) != -1) {
        if (h->h[pos] < h->h[indicePai(h, pos)]) {
            int aux = h->h[pos];
            h->h[pos] = h->h[indicePai(h, pos)];
            h->h[indicePai(h, pos)] = aux;
            ajustarSubindo(h, indicePai(h, pos));
        }
    }
}

void ajustarDescendo(Heap* h, int pos) {
    if (pos != -1 && indiceFilhoEsq(h, pos) != -1) {
        int indiceMenor = indiceFilhoEsq(h, pos);
        if (indiceFilhoDir(h, pos) != -1 && h->h[indiceFilhoDir(h, pos)] < h->h[indiceMenor]) {
            indiceMenor = indiceFilhoDir(h, pos);
        }

        printf("%d\n", indiceMenor);

        if (h->h[indiceMenor] < h->h[pos]) {
            int aux = h->h[pos];
            h->h[pos] = h->h[indiceMenor];
            h->h[indiceMenor] = aux;
            ajustarDescendo(h, indiceMenor);
        }
    }
}

void inserir_elem(Heap* h, int obj) {
    h->h[h->last_elem] = obj;
    h->last_elem++;

    ajustarSubindo(h, h->last_elem - 1);
}

int remover_elem(Heap* h) {
    if (h->last_elem == 0) {
        return -1;
    } else {
        int ret = h->h[0];
        h->last_elem--;
        h->h[0] = h->h[h->last_elem];
        ajustarDescendo(h, 0);
        return ret;
    }
}


void print_heap(Heap* h) {
    printf("[");
    for (int i = 0; i < h->last_elem; i++) {
        if (i == h->last_elem - 1) {
            printf("%d", h->h[i]);
        } else {
            printf("%d, ", h->h[i]);
        }
    }
    printf("]\n");
}


int main() {
    int heap_size;
    printf("Digite o tamanho do vetor heap alocado: ");
    scanf("%d", &heap_size);

    Heap* h = create_heap(heap_size);

    while (1) {
        printf("\n1. Inserir um elemento x na heap.\n");
        printf("2. Remover um elemento - o elemento removido deve ser impresso na tela.\n");
        printf("3. Imprimir a heap.\n");
        printf("4. Sair\n");

        int opt;
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                printf("Digite o valor do elemento: ");
                int obj;
                scanf("%d", &obj);
                inserir_elem(h, obj);
                break;
            }
            case 2: {
                int elem = remover_elem(h);
                if (elem != -1) {
                    printf("%d\n", elem);
                }
                break;
            }
            case 3: {
                print_heap(h);
                break;
            }
            case 4: {
                free(h->h);
                free(h);
                exit(0);
            }
        }
    }

    return 0;
}