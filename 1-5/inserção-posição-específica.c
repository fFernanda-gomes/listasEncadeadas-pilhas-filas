#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_posicao(No **lista, int valor, int pos) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;

    if (pos == 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    No *atual = *lista;
    for (int i = 0; atual != NULL && i < pos - 1; i++) {
        atual = atual->prox;
    }

    if (atual == NULL) return;

    novo->prox = atual->prox;
    atual->prox = novo;
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
    inserir_posicao(&lista, 1, 0);
    inserir_posicao(&lista, 3, 1);
    inserir_posicao(&lista, 2, 1);
    imprimir_lista(lista);
    return 0;
}
