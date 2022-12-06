#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


struct lista {
    int quant;
    int vet[MAX];
};


Lista *lista_criar() {
    Lista *l;
    l = (Lista *) malloc(sizeof(Lista));
    if (l != NULL) {
        l->quant = 0;
    }

    return l;

}

void lista_clear(Lista *l) {
    free(l);
}

void lista_append(Lista *l, int valor) {
    if (l->quant + 1 <= MAX) {
        l->quant++;
        l->vet[l->quant - 1] = valor;
    }
}

void lista_trocar(Lista *l, int index1, int index2) {
    int aux = l->vet[index1];
    l->vet[index1] = l->vet[index2];
    l->vet[index2] = aux;
}

void lista_insert(Lista *l, int valor) {
    
    lista_append(l, valor);
    for (int i = l->quant - 1; i > 0; i--) {
        lista_trocar(l, i, i - 1);
    }
}

int lista_get(Lista *l, int index) {
    return l->vet[index];
}
