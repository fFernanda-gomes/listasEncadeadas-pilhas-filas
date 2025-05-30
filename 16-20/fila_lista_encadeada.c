#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void inicializar(Fila* f) {
    f->inicio = f->fim = NULL;
}

void enfileirar(Fila* f, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo;
    else f->inicio = novo;
    f->fim = novo;
}

int desenfileirar(Fila* f) {
    if (!f->inicio) return -1;
    No* temp = f->inicio;
    int val = temp->valor;
    f->inicio = f->inicio->prox;
    if (!f->inicio) f->fim = NULL;
    free(temp);
    return val;
}

int main() {
    Fila f;
    inicializar(&f);
    enfileirar(&f, 1);
    enfileirar(&f, 2);
    enfileirar(&f, 3);
    
    printf("%d ", desenfileirar(&f));
    printf("%d ", desenfileirar(&f));
    printf("%d\n", desenfileirar(&f));
    
    return 0;
}
