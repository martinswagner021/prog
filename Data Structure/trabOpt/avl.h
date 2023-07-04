#ifndef AVL
#define AVL

typedef struct avl *avl;

avl avl_inicializar();
avl avl_destruir(avl a);

void inserir(avl a, int chave, void* info);
void remover(avl a, int chave);
void existe(avl a, int chave);
avl buscar(avl a, int chave);
void imprimir(avl a, int chave);

#endif
