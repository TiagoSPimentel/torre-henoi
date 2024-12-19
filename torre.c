#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

//imprime  as torres
void imprimir_torres(Pilha *torres[], int n){
    int altura_maxima = 0;
    //calcula maior altua entre as torres
    for(int i = 0; i < 3; i++){
        if(torres[i]->tamanho > altura_maxima){
            altura_maxima = torres[i]->tamanho;
        }
    }
     //imprime as torres
    for(int nivel = altura_maxima - 1; nivel >= 0; nivel--){//percorre os niveis das torres

        //verificar se ha discos em alguma torre
        for(int t = 0; t < 3; t++){
            No *atual = torres[t]->topo; // Pega o topo da torre
            int altura_atual = torres[t]->tamanho; //pega altuta da torre atual

            for(int h = 0; h < altura_atual - nivel - 1 && atual; h++){
                atual = atual->proximo;
            }
            //imprime o disco na torre
            if(atual && altura_atual > nivel){ 
                printf("%d ", atual->disco);
            } else{
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("- - -\n");
    printf("1 2 3\n");
    printf("\n");
}

//move um disco da torre origem para a torre destino
void mover_disco(Pilha *origem, Pilha *destino){
    int disco;
    if(top(origem)){ //desempilha da prigem
        push(destino, disco); //empilha no destino
    }
}
//verifica movimentos validos
int movimentos(Pilha *origem, Pilha *destino){
    int topo_origem, topo_destino;

    if(topo_pilha(origem, &topo_origem)){
        if(topo_pilha(destino, &topo_destino)){
            return topo_origem < topo_destino; //adicona disco na torre se o disco de origem for menor que o destino
        }
        return 1; //adiciona se destino tiver vazio
    }
    return 0; // origrm vazio é invalido
}
int main(){
    int n;
    printf("Indique a quantidade de discos N: ");
    scanf("%d", &n);
    printf("\n");
    Pilha *torres[3];

    //cria 3 pilhas
    for(int i = 0; i < 3; i++){
        torres[i] = criar_pilha();
    }
    //empilha os discos
    for(int i = n; i > 0; i--){
        push(torres[0], i);
    }

    imprimir_torres(torres, n);

    int origem, destino, passos = 0;
     int movimento_valido = 0;

    //enquanto o pino 3 e o pino 2 não estiverem cheios 
    while(torres[2]->tamanho < n && torres[1]->tamanho < n){

        printf("Digite a jogada (origem,destino): ");
        scanf("%d,%d", &origem, &destino);
        printf("\n");
        origem--;
        destino--;

        //verifica se o movimento é valido
       if (origem >= 0 && origem < 3 && destino >= 0 && destino < 3) {
            switch (movimentos(torres[origem], torres[destino])) {  // Verifica se o movimento é válido
                case 1:  // Movimento válido
                    mover_disco(torres[origem], torres[destino]);
                    passos++;
                    movimento_valido = 1;
                    break;
                case 0:  // Movimento inválido (não pode mover)
                    movimento_valido = 0;
                    break;
                default:
                    movimento_valido = 0;
                    break;
            }

            // Se o movimento foi inválido, exibe uma mensagem de erro
            if (!movimento_valido) {
                printf("Movimento invalido! Tente novamente.\n");
                imprimir_torres(torres, n);
            } else {
                // Se o movimento foi válido, imprime as torres
                imprimir_torres(torres, n);
            }
        } else {
            printf("Entrada invalida! As torres sao numeradas de 1 a 3.\n");
            imprimir_torres(torres, n);
        }
    }
    printf("PARABENS!!! Jogo concluido em %d passos!\n", passos);

    for(int i = 0; i < 3; i++){
        destruir_pilha(torres[i]);
    }

    return 0;
}