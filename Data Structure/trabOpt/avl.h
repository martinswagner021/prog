#ifndef AVL
#define AVL

typedef struct avl *avl;

avl avl_inicializar();
avl avl_destruir(avl a);

avl inserir(avl a, int chave, void* info, int tamObj);
avl remover(avl a, int chave);
int existe(avl a, int chave);
avl buscar(avl a, int chave);
void imprimir(avl a);

#endif

