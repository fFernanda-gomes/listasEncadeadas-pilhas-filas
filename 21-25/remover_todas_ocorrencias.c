#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* remover_todas_ocorrencias(No* head, int alvo) {
    while (head && head->valor == alvo) {
        No* temp = head;
        head = head->prox;
        free(temp);
    }
    No* atual = head;
    while (atual && atual->prox) {
        if (atual->prox->valor == alvo) {
            No* temp = atual->prox;
            atual->prox = atual->prox->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
    return head;
}

void imprimir(No* l) {
    while (l) {
        printf("%d ", l->valor);
        l = l->prox;
    }
    printf("\n");
}

No* novo_no(int val) {
    No* no = malloc(sizeof(No));
    no->valor = val;
    no->prox = NULL;
    return no;
}

int main() {
    No* lista = novo_no(1);
    lista->prox = novo_no(2);
    lista->prox->prox = novo_no(2);
    lista->prox->prox->prox = novo_no(3);
    
    lista = remover_todas_ocorrencias(lista, 2);
    imprimir(lista);
    
    return 0;
}