#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void push(Pilha* p, int val) {
    p->dados[++(p->topo)] = val;
}

int pop(Pilha* p) {
    return p->dados[(p->topo)--];
}

int is_empty(Pilha* p) {
    return p->topo == -1;
}

typedef struct {
    Pilha entrada;
    Pilha saida;
} Fila;

void enfileirar(Fila* f, int val) {
    push(&f->entrada, val);
}

int desenfileirar(Fila* f) {
    if (is_empty(&f->saida)) {
        while (!is_empty(&f->entrada)) {
            push(&f->saida, pop(&f->entrada));
        }
    }
    return pop(&f->saida);
}

int main() {
    Fila f = {{.topo = -1}, {.topo = -1}};
    
    enfileirar(&f, 1);
    enfileirar(&f, 2);
    enfileirar(&f, 3);
    
    printf("%d ", desenfileirar(&f));
    printf("%d ", desenfileirar(&f));
    printf("%d\n", desenfileirar(&f));
    
    return 0;
}
