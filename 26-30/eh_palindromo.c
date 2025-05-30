#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* inverter(No* head) {
    No* prev = NULL;
    while (head) {
        No* next = head->prox;
        head->prox = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int comparar(No* a, No* b) {
    while (a && b) {
        if (a->dado != b->dado) return 0;
        a = a->prox;
        b = b->prox;
    }
    return 1;
}

int eh_palindromo(No* head) {
    No *rapido = head, *lento = head;
    while (rapido && rapido->prox) {
        rapido = rapido->prox->prox;
        lento = lento->prox;
    }

    No* segunda_metade = inverter(lento);
    int res = comparar(head, segunda_metade);
    inverter(segunda_metade);
    return res;
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

int main() {
    No* lista = NULL;
    
    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);
    inserir(&lista, 2);
    inserir(&lista, 1);
    
    printf("%d\n", eh_palindromo(lista));
    return 0;
}
