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

void lista_insert_sorted(Lista *l, int valor) {
    lista_append(l, valor);
    int valor_index = l->quant - 1;

    for (int i = l->quant - 1; i >= 0; i--) {
        if (valor < l->vet[i]) {
            lista_trocar(l, valor_index, i);
            valor_index = i;
        }
    }
};

int lista_full(Lista *l) {
    return l->quant == MAX;
};

int lista_empty(Lista *l) {
    return l->quant == 0;
};

void lista_remove(Lista *l, int index) {
    if (l->quant - 1 <= index) {
        for (int i = index; i <= l->quant - 2; i++) {
            lista_trocar(l, i, i + 1);
        }
        l->quant--;
    }
};

int lista_size(Lista *l) {
    return l->quant;
};

void lista_print(Lista *l){
    for (int i = 0; i < l->quant - 1; i++) {
        printf("%d\n", l->vet[i]);
    }
}
