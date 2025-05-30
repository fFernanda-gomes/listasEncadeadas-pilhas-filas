#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* valor;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enfileirar(Fila* f, char* val) {
    No* novo = malloc(sizeof(No));
    novo->valor = strdup(val);
    novo->prox = NULL;
    if (f->fim) f->fim->prox = novo;
    else f->inicio = novo;
    f->fim = novo;
}

char* desenfileirar(Fila* f) {
    if (!f->inicio) return NULL;
    No* temp = f->inicio;
    char* val = temp->valor;
    f->inicio = f->inicio->prox;
    if (!f->inicio) f->fim = NULL;
    free(temp);
    return val;
}

void gerar_binarios(int N) {
    Fila f = {NULL, NULL};
    enfileirar(&f, "1");
    for (int i = 0; i < N; i++) {
        char* bin = desenfileirar(&f);
        printf("%s ", bin);
        
        char s1[20], s2[20];
        sprintf(s1, "%s0", bin);
        sprintf(s2, "%s1", bin);
        
        enfileirar(&f, s1);
        enfileirar(&f, s2);
        free(bin);
    }
    printf("\n");
}

int main() {
    gerar_binarios(10);
    return 0;
}
