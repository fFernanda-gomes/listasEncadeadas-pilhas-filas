#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void pilha_inicializar(Pilha *p) {
    p->topo = -1;
}

int pilha_esta_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_esta_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void pilha_push(Pilha *p, int valor) {
    if (!pilha_esta_cheia(p)) {
        p->dados[++p->topo] = valor;
    } else {
        printf("pilha cheia\n");
    }
}

int pilha_pop(Pilha *p) {
    if (!pilha_esta_vazia(p)) {
        return p->dados[p->topo--];
    } else {
        printf("pilha vazia\n");
        return -1;
    }
}

int pilha_topo(Pilha *p) {
    if (!pilha_esta_vazia(p)) {
        return p->dados[p->topo];
    } else {
        printf("Pilha vazia\n");
        return -1;
    }
}

int main() {
    Pilha p;
    pilha_inicializar(&p);
    pilha_push(&p, 10);
    pilha_push(&p, 20);
    
    printf("Topo: %d\n", pilha_topo(&p));
    printf("Pop: %d\n", pilha_pop(&p));
    printf("Pop: %d\n", pilha_pop(&p));
    printf("Pop: %d\n", pilha_pop(&p));
    
    return 0;
}
