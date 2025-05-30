#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int detectar_ciclo(No* cabeca) {
    No* lento = cabeca;
    No* rapido = cabeca;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
        if (lento == rapido) return 1;
    }
    return 0;
}

int main() {
    No* a = malloc(sizeof(No));
    No* b = malloc(sizeof(No));
    No* c = malloc(sizeof(No));
    No* d = malloc(sizeof(No));
    
    a->prox = b; b->prox = c; c->prox = d; d->prox = b;
    printf("%d\n", detectar_ciclo(a));
    
    d->prox = NULL;
    printf("%d\n", detectar_ciclo(a));
    
    return 0;
}
