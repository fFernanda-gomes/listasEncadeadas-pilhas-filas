#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void push(Pilha* p, int val) {
    p->dados[++p->topo] = val;
}

int pop(Pilha* p) {
    return p->dados[p->topo--];
}

typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} Fila;

void enfileirar(Fila* f, int val) {
    f->dados[f->fim++] = val;
    f->fim %= MAX;
    f->tamanho++;
}

int desenfileirar(Fila* f) {
    int val = f->dados[f->inicio++];
    f->inicio %= MAX;
    f->tamanho--;
    return val;
}

void inverter_primeiros_k(Fila* f, int k) {
    Pilha p = {.topo = -1};
    for (int i = 0; i < k; i++) push(&p, desenfileirar(f));
    while (p.topo != -1) enfileirar(f, pop(&p));
    for (int i = 0; i < f->tamanho - k; i++) enfileirar(f, desenfileirar(f));
}

int main() {
    Fila f = {.inicio = 0, .fim = 0, .tamanho = 0};
    
    for (int i = 1; i <= 5; i++) enfileirar(&f, i);
    
    inverter_primeiros_k(&f, 3);
    
    while (f.tamanho) printf("%d ", desenfileirar(&f));
    
    return 0;
}
