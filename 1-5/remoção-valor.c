#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void remover_valor(No **lista, int valor) {
    No *atual = *lista, *anterior = NULL;

    while (atual && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual) return;

    if (!anterior) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
}

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;
    No *n1 = malloc(sizeof(No)); n1->dado = 1;
    No *n2 = malloc(sizeof(No)); n2->dado = 2;
    No *n3 = malloc(sizeof(No)); n3->dado = 3;
    n1->prox = n2; n2->prox = n3; n3->prox = NULL;
    lista = n1;

    remover_valor(&lista, 2);
    imprimir_lista(lista);
    return 0;
}
