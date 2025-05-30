#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilhas;

void inicializar(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

void push1(DuasPilhas* p, int val) {
    if (p->topo1 + 1 == p->topo2) {
        printf("estouro\n");
        return;
    }
    p->dados[++p->topo1] = val;
}

void push2(DuasPilhas* p, int val) {
    if (p->topo2 - 1 == p->topo1) {
        printf("estouro\n");
        return;
    }
    p->dados[--p->topo2] = val;
}

int pop1(DuasPilhas* p) {
    return p->dados[p->topo1--];
}

int pop2(DuasPilhas* p) {
    return p->dados[p->topo2++];
}

int main() {
    DuasPilhas p;
    inicializar(&p);
    
    push1(&p, 1);
    push2(&p, 9);
    push1(&p, 2);
    push2(&p, 8);
    
    printf("Pop1: %d\n", pop1(&p));
    printf("Pop2: %d\n", pop2(&p));
    
    return 0;
}