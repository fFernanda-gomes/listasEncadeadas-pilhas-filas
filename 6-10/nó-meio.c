#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *temp = *lista;
        while (temp->prox != NULL) temp = temp->prox;
        temp->prox = novo;
    }
}

No* encontrar_meio(No *lista) {
    if (lista == NULL) return NULL;
    No *lento = lista;
    No *rapido = lista;
    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
}

int main() {
    No *lista = NULL;
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 40);
    inserir_fim(&lista, 50);
    No *meio = encontrar_meio(lista);
    
    if (meio)
        printf("No do meio: %d\n", meio->dado);
    else
        printf("Lista vazia\n");
    return 0;
}
