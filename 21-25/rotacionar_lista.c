#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int tamanho_lista(No* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->prox;
    }
    return count;
}

No* rotacionar_lista(No* head, int k) {
    if (!head || !head->prox || k == 0) return head;

    int tamanho = tamanho_lista(head);
    k %= tamanho;
    if (k == 0) return head;

    No* atual = head;
    for (int i = 1; i < tamanho - k; i++) atual = atual->prox;

    No* novo_head = atual->prox;
    atual->prox = NULL;

    No* temp = novo_head;
    while (temp->prox) temp = temp->prox;
    temp->prox = head;

    return novo_head;
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
    lista->prox->prox = novo_no(3);
    lista->prox->prox->prox = novo_no(4);
    lista->prox->prox->prox->prox = novo_no(5);
    
    lista = rotacionar_lista(lista, 2);
    imprimir(lista);
    
    return 0;
}