#ifndef AVL
#define AVL

// Estrutura AVL.
typedef struct avl *avl;

// Retorna uma nova AVL vazia.
avl avl_inicializar();
// Destroi toda a AVL.
avl avl_destruir(avl a);

// Retorna a nova AVL com o elemento inserido.
avl inserir(avl a, int chave, void* obj, int tamObj);
// Retorna a AVL com o elemento removido.
avl remover(avl a, int chave);
// Retorna 1 se existe a chave, 0 se nao.
int existe(avl a, int chave);
// Retorna a chave e copia para o obj o valor correspondente a chave, retorna 0 caso nao exista.
int buscar(avl a, int chave, void* obj, int tamObj);
// Imprime em largura por suas respectivas chaves.
void imprimir(avl a);

#endif