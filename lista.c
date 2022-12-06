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
    l->vet[l->quant] = valor;
    l->quant++;
}

void lista_insert(Lista *l, int valor) {
    
    for (int i = l->quant - 1; i >= 0; i--) {
        l->vet[i + 1] = l->vet[i];
    }
    l->vet[0] = valor;
    l->quant++;

}

int lista_get(Lista *l, int index) {
    return l->vet[index];
}
