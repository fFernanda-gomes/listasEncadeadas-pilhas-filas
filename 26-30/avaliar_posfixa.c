#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int avaliar_posfixa(char* expr) {
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            switch (token[0]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop();
}

int main() {
    char expr[] = "3 4 + 2 *";
    printf("Resultado: %d\n", avaliar_posfixa(expr));
    
    return 0;
}
