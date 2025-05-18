#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (top == TAMANHO - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("\n%d foi empilhado com sucesso!\n", data);
}


int pop() {
    if (isEmpty()) {
        printf("Pilha vazia! Nada para desempilhar.\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    return temp;
}


void imprime_pilha() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pilha: ");
    for (int i = 0; i <= top; i++) {
        printf("%d -> ", stack[i]);
    }
    printf("topo\n");
}


void topo_pilha() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Topo: %d\n", stack[top]);
}


int main() {
	setlocale(LC_ALL,"Portuguese");
    int opcao, valor;

    do {
        printf("\n==== MENU PILHA ====\n");
        printf("1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Imprimir pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
           
            switch (opcao) {
            case 1:
                printf("Digite um número para empilhar: ");
                scanf("%d", &valor);
                push(valor);
                break;
            case 2:
                valor = pop();
                if (valor != -1)
                    printf("Valor desempilhado: %d\n", valor);
                break;
            case 3:
                imprime_pilha();
                break;
                 }
                 
                 

    } while (opcao != 0);

    return 0;
}

