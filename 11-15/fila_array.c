#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente, tras;
    int tamanho;
} Fila;

void fila_inicializar(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int fila_esta_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_esta_cheia(Fila *f) {
    return f->tamanho == MAX;
}

void fila_enfileirar(Fila *f, int valor) {
    if (fila_esta_cheia(f)) {
        printf("fila cheia\n");
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->dados[f->tras] = valor;
    f->tamanho++;
}

int fila_desenfileirar(Fila *f) {
    if (fila_esta_vazia(f)) {
        printf("fila vazia\n");
        return -1;
    }
    int valor = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return valor;
}

int fila_frente(Fila *f) {
    if (fila_esta_vazia(f)) {
        printf("fila vazia\n");
        return -1;
    }
    return f->dados[f->frente];
}

int main() {
    Fila f;
    fila_inicializar(&f);
    fila_enfileirar(&f, 10);
    fila_enfileirar(&f, 20);
    
    printf("frente: %d\n", fila_frente(&f));
    
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    printf("desenfileirar: %d\n", fila_desenfileirar(&f));
    
    return 0;
}
