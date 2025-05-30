#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int minimos[MAX];
    int topo;
} PilhaMin;

void inicializar(PilhaMin* p) {
    p->topo = -1;
}

void push(PilhaMin* p, int val) {
    p->dados[++p->topo] = val;
    if (p->topo == 0) p->minimos[p->topo] = val;
    else p->minimos[p->topo] = val < p->minimos[p->topo - 1] ? val : p->minimos[p->topo - 1];
}

int pop(PilhaMin* p) {
    return p->dados[p->topo--];
}

int top(PilhaMin* p) {
    return p->dados[p->topo];
}

int obter_minimo(PilhaMin* p) {
    return p->minimos[p->topo];
}

int main() {
    PilhaMin p;
    inicializar(&p);
    
    push(&p, 3);
    push(&p, 5);
    push(&p, 2);
    push(&p, 1);
    
    printf("Min: %d\n", obter_minimo(&p));
    pop(&p);
    printf("Min: %d\n", obter_minimo(&p));
    
    return 0;
}