#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_inicio(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
        return;
    }

    No *atual = *lista;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
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
    inserir_fim(&lista, 10);
    inserir_inicio(&lista, 5);
    imprimir_lista(lista);
    return 0;
}
