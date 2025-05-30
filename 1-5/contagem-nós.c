#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

int contar_nos(No *lista) {
    int cont = 0;
    while (lista) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

int main() {
    No *lista = malloc(sizeof(No));
    lista->dado = 1;
    lista->prox = malloc(sizeof(No));
    lista->prox->dado = 2;
    lista->prox->prox = NULL;

    printf("quantidade de nos: %d\n", contar_nos(lista));
    return 0;
}
