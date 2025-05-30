#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* unir_listas_ordenadas(No* a, No* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->valor < b->valor) {
        a->prox = unir_listas_ordenadas(a->prox, b);
        return a;
    } else {
        b->prox = unir_listas_ordenadas(a, b->prox);
        return b;
    }
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
    No* a = novo_no(1);
    a->prox = novo_no(3);
    a->prox->prox = novo_no(5);
    
    No* b = novo_no(2);
    b->prox = novo_no(4);
    b->prox->prox = novo_no(6);
    
    No* unida = unir_listas_ordenadas(a, b);
    imprimir(unida);
    
    return 0;
}
