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
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;
    }
}

int contar_ocorrencias(No *lista, int valor) {
    int count = 0;
    while (lista) {
        if (lista->dado == valor)
            count++;
        lista = lista->prox;
    }
    return count;
}

int main() {
    No *lista = NULL;
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 20);
    
    int val = 5;
    printf("numero de ocorrencias de %d: %d\n", val, contar_ocorrencias(lista, val));
    
    return 0;
}
