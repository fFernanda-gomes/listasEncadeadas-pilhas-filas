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

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

void inverter_lista(No **lista) {
    No *prev = NULL, *current = *lista, *next = NULL;
    while (current) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    *lista = prev;
}

int main() {
    No *lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    
    printf("Original: ");
    imprimir_lista(lista);
    inverter_lista(&lista);
    
    printf("Invertida: ");
    imprimir_lista(lista);
    return 0;
}
