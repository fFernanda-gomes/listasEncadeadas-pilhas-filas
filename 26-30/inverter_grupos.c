#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* inverter_grupo(No* head, int k) {
    No* prev = NULL;
    No* curr = head;
    No* next = NULL;
    int count = 0;

    while (curr && count < k) {
        next = curr->prox;
        curr->prox = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        head->prox = inverter_grupo(next, k);

    return prev;
}

void inserir(No** head, int val) {
    No* novo = malloc(sizeof(No));
    novo->dado = val;
    novo->prox = NULL;
    if (!*head) {
        *head = novo;
        return;
    }
    No* temp = *head;
    while (temp->prox) temp = temp->prox;
    temp->prox = novo;
}

void imprimir(No* head) {
    while (head) {
        printf("%d ", head->dado);
        head = head->prox;
    }
    printf("\n");
}

int main() {
    No* lista = NULL;
    
    for (int i = 1; i <= 5; i++) inserir(&lista, i);
    
    lista = inverter_grupo(lista, 2);
    imprimir(lista);
    
    return 0;
}
