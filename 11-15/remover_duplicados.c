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

void imprimir_lista(No *lista) {
    while (lista) {
        printf("%d ", lista->dado);
        lista = lista->prox;
    }
    printf("\n");
}

void remover_duplicados(No *lista) {
    No *ptr1, *ptr2, *dup;
    ptr1 = lista;
    while (ptr1 != NULL && ptr1->prox != NULL) {
        ptr2 = ptr1;
        while (ptr2->prox != NULL) {
            if (ptr1->dado == ptr2->prox->dado) {
                dup = ptr2->prox;
                ptr2->prox = ptr2->prox->prox;
                free(dup);
            } else {
                ptr2 = ptr2->prox;
            }
        }
        ptr1 = ptr1->prox;
    }
}

int main() {
    No *lista = NULL;
    inserir_fim(&lista, 10);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 20);
    inserir_fim(&lista, 30);
    inserir_fim(&lista, 10);
    
    printf("original: ");
    imprimir_lista(lista);
    
    remover_duplicados(lista);
    
    printf("sem duplicados: ");
    imprimir_lista(lista);
    
    return 0;
}
