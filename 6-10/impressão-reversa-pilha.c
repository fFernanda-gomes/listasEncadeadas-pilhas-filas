#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

typedef struct Pilha {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

void pilha_inicializar(Pilha *p, int capacidade) {
    p->dados = malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
}

int pilha_esta_vazia(Pilha *p) {
    return p->topo == -1;
}

void pilha_push(Pilha *p, int valor) {
    if (p->topo < p->capacidade - 1)
        p->dados[++p->topo] = valor;
}

int pilha_pop(Pilha *p) {
    if (!pilha_esta_vazia(p))
        return p->dados[p->topo--];
    return -1;
}

void inserir_fim(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *temp = *lista;
        while (temp->prox) temp = temp->prox;
        temp->prox = novo;
    }
}

void imprimir_reversa(No *lista) {
    Pilha pilha;
    pilha_inicializar(&pilha, 100);
    No *temp = lista;
    while (temp) {
        pilha_push(&pilha, temp->dado);
        temp = temp->prox;
    }
    while (!pilha_esta_vazia(&pilha)) {
        printf("%d ", pilha_pop(&pilha));
    }
    printf("\n");
    free(pilha.dados);
}

int main() {
    No *lista = NULL;
    inserir_fim(&lista, 1);
    inserir_fim(&lista, 2);
    inserir_fim(&lista, 3);
    
    printf("Impressao reversa: ");
    imprimir_reversa(lista);
    return 0;
}
