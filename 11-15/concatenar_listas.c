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

void concatenar_listas(No **lista1, No *lista2) {
    if (*lista1 == NULL) {
        *lista1 = lista2;
    } else {
        No *temp = *lista1;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = lista2;
    }
}

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
    No *lista1 = NULL;
    No *lista2 = NULL;
    inserir_fim(&lista1, 1);
    inserir_fim(&lista1, 2);
    inserir_fim(&lista2, 3);
    inserir_fim(&lista2, 4);
    
    printf("lista 1: ");
    imprimir_lista(lista1);
    
    printf("lista 2: ");
    imprimir_lista(lista2);
    
    concatenar_listas(&lista1, lista2);
    
    printf("concatenada: ");
    imprimir_lista(lista1);
    
    return 0;
}
