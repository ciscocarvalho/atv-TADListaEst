#include <stdio.h>
#include "lista.h"

int main() {

    Lista *l;

    l = criar();
    append(l, 10);
    append(l, 20);
    append(l, 30);
    printf("Valor índice 0: %d\n", get(l, 0));
    insert(l, 50);
    printf("Valor índice 0: %d\n", get(l, 0));
    printf("Valor índice 3: %d\n", get(l, 3));

    return 0;
}