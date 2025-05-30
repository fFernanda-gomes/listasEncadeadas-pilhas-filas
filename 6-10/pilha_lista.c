#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void pilha_inicializar(Pilha *p) {
    p->topo = NULL;
}

int pilha_esta_vazia(Pilha *p) {
    return p->topo == NULL;
}

void pilha_push(Pilha *p, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int pilha_pop(Pilha *p) {
    if (pilha_esta_vazia(p)) {
        printf("pilha vazia\n");
        return -1;
    }
    No *temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int pilha_topo(Pilha *p) {
    if (pilha_esta_vazia(p)) {
        printf("pilha vazia\n");
        return -1;
    }
    return p->topo->dado;
}

int main() {
    Pilha p;
    pilha_inicializar(&p);
    pilha_push(&p, 5);
    pilha_push(&p, 15);
    
    printf("topo: %d\n", pilha_topo(&p));
    printf("pop: %d\n", pilha_pop(&p));
    printf("pop: %d\n", pilha_pop(&p));
    printf("pop: %d\n", pilha_pop(&p));
    
    return 0;
}
