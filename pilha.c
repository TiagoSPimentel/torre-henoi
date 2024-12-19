#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar uma pilha
Pilha *criar_pilha(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if(p){ // Se a alocação for bem-sucedida
        p->topo = NULL;
        p->tamanho = 0;
    }
    return p;
}
// Função para destruir a pilha e liberar a memória alocada
void destruir_pilha(Pilha *p){
    No *atual = p->topo; // Começa do topo da pilha
    while(atual){
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(p);
}
// Função para empilhar um disco na pilha
int push(Pilha *p, int disco){
    No *novo = (No *)malloc(sizeof(No));// Cria um novo nó para o disco
    if (!novo){ 
        return 0; //não alocou
    } 
    novo->disco = disco;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tamanho++;
    return 1;
}
// Função para remover e retornar o valor do topo da pilha
int top(Pilha *p){
    if (pilha_vazia(p)){
        return -1;  
    }
    No *temp = p->topo;
    int disco_topo = temp->disco;  // Atribui o valor do topo
    p->topo = temp->proximo;
    free(temp);
    p->tamanho--;
    return disco_topo;  // Retorna o valor do topo removido
}

/// Função para apenas verificar o disco do topo
int topo_pilha(Pilha *p, int *disco){
    if (pilha_vazia(p)) return 0;
    *disco = p->topo->disco;  // Atribui o disco do topo
    return 1;
}
//retorna pilha vazia
int pilha_vazia(Pilha *p){
    return p->topo == NULL;
}
// Função para imprimir todos os elementos da pilha
void imprimir_pilha(Pilha *p){
    No *atual = p->topo;
    if (pilha_vazia(p)){
        printf("\n");
        return;
    }

    while(atual){ // Enquanto houver elementos na pilha
        printf("|%d|\n", atual->disco);
        atual = atual->proximo;
    }
    printf("\n");
}