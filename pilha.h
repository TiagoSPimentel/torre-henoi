#ifndef PILHA_H
#define PILHA_H


// Estrutura que representa um nó da pilha
typedef struct No{
    int disco;          // disco armazenado no nó
    struct No *proximo; // Ponteiro para o próximo nó na pilha
}No;

// Estrutura que representa a pilha
typedef struct Pilha{
    No *topo;    // Ponteiro para o topo da pilha
    int tamanho; // Tamanho atual da pilha (número de elementos)
}Pilha;

// Função para criar uma pilha
Pilha *criar_pilha();

// Função para destruir a pilha e liberar a memória alocada
void destruir_pilha(Pilha *p);

// Função para empilhar um disco na pilha
int push(Pilha *p, int disco);

// Função para remover o disco do topo da pilha e retorná-lo
int top(Pilha *p);

// Função para apenas retornar o disco do topo da pilha sem removê-lo
int topo_pilha(Pilha *p, int *disco);

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha *p);

// Função para imprimir todos os elementos da pilha
void imprimir_pilha(Pilha *p);


#endif

//exemlo de utilização
/* #include <stdio.h>
#include "pilha.h"

int main() {
    // Criação de uma nova pilha
    Pilha *minha_pilha = criar_pilha();

    // Empilhando valores na pilha
    push(minha_pilha, 1);
    push(minha_pilha, 2);
    push(minha_pilha, 3);

    // Imprimindo o conteúdo da pilha
    printf("Conteúdo da pilha após empilhar 1, 2 e 3:\n");
    imprimir_pilha(minha_pilha);

    // Verificando o topo da pilha (sem remover)
    int topo;
    if (topo_pilha(minha_pilha, &topo)) {
        printf("O valor do topo da pilha é: %d\n", topo);
    }

    // Removendo o valor do topo da pilha
    if (top(minha_pilha, &topo)) {
        printf("O valor removido do topo foi: %d\n", topo);
    }

    // Imprimindo a pilha após a remoção
    printf("Conteúdo da pilha após remover o topo:\n");
    imprimir_pilha(minha_pilha);

    // Destruindo a pilha e liberando a memória
    destruir_pilha(minha_pilha);

    return 0;
}

saída esperada:
Conteúdo da pilha após empilhar 1, 2 e 3:
3
2
1

O valor do topo da pilha é: 3
O valor removido do topo foi: 3
Conteúdo da pilha após remover o topo:
2
1

*/