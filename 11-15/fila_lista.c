#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *frente;
    No *tras;
} Fila;

void fila_inicializar(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
}

int fila_esta_vazia(Fila *f) {
    return f->frente == NULL;
}

void fila_enfileirar(Fila *f, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (fila_esta_vazia(f)) {
        f->frente = novo;
    } else {
        f->tras->prox = novo;
    }
    f->tras = novo;
}

int fila_desenfileirar(Fila *f) {
    if (fila_esta_vazia(f)) {
        printf("fila vazia\n");
        return -1;
    }
    No *temp = f->frente;
    int valor = temp->dado;
    f->frente = temp->prox;
    if (f->frente == NULL)
        f->tras = NULL;
    free(temp);
    return valor;
}

int fila_frente(Fila *f) {
    if (fila_esta_vazia(f)) {
        printf("fila vazia\n");
        return -1;
    }
    return f->frente->dado;
}

int main() {
    Fila f;
    fila_inicializar(&f);
    fila_enfileirar(&f, 100);
    fila_enfileirar(&f, 200);
    
    printf("frente: %d\n", fila_frente(&f));
    
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    
    return 0;
}
