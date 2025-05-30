#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

int buscar_elemento(No *lista, int valor) {
    while (lista) {
        if (lista->dado == valor)
            return 1;
        lista = lista->prox;
    }
    return 0;
}

int main() {
    No *lista = malloc(sizeof(No));
    lista->dado = 10;
    lista->prox = malloc(sizeof(No));
    lista->prox->dado = 20;
    lista->prox->prox = NULL;

    printf("%d\n", buscar_elemento(lista, 20));
    printf("%d\n", buscar_elemento(lista, 99));
    return 0;
}
