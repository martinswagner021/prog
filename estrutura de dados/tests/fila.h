#ifndef FILAH
#define FILAH

typedef struct fila *fila;

fila inicializar();
fila destruir();

void inserir(fila f, int id, char* nome, float peso, int anoFabricacao);

void printeqs();

#endif