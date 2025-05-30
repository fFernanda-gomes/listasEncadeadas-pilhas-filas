#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int obter_tamanho(No* l) {
    int tamanho = 0;
    while (l) {
        tamanho++;
        l = l->prox;
    }
    return tamanho;
}

No* encontrar_intersecao(No* a, No* b) {
    int tamA = obter_tamanho(a);
    int tamB = obter_tamanho(b);

    while (tamA > tamB) {
        a = a->prox;
        tamA--;
    }
    while (tamB > tamA) {
        b = b->prox;
        tamB--;
    }

    while (a && b) {
        if (a == b) return a;
        a = a->prox;
        b = b->prox;
    }

    return NULL;
}

No* novo_no(int val) {
    No* no = malloc(sizeof(No));
    no->valor = val;
    no->prox = NULL;
    return no;
}

int main() {
    No* comum = novo_no(8);
    comum->prox = novo_no(10);

    No* a = novo_no(3);
    a->prox = novo_no(6);
    a->prox->prox = comum;

    No* b = novo_no(1);
    b->prox = comum;

    No* intersecao = encontrar_intersecao(a, b);
    if (intersecao)
        printf("Interseção em: %d\n", intersecao->valor);
    else
        printf("Sem interseção\n");

    return 0;
}