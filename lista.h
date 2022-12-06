#define MAX 5

typedef struct lista Lista;

Lista *lista_criar();

void lista_append(Lista *l, int valor);
void lista_insert(Lista *l, int valor);
void lista_insert_sorted(Lista *l, int valor); // inserir ordenado
void lista_clear(Lista *l);
int lista_get(Lista *l, int index);
int lista_full(Lista *l); // está cheia?
int lista_empty(Lista *l); // está vazia?
void lista_remove(Lista *l, int index); // remover por índice
int lista_size(Lista *l); // retornar o tamanho da lista
void lista_print(Lista *l); // imprimir os elementos da lista
