Jogo da Torre de Hanoi


- Descrição do Projeto:

Este projeto implementa o jogo clássico da Torre de Hanoi utilizando a estrutura de dados Pilha. O objetivo do jogo é mover discos de uma torre para outra, respeitando a regra de que um disco maior nunca pode ser colocado sobre um disco menor. O jogo termina quando todos os discos estão na torre de destino.


- Estrutura de Pastas e Arquivos:


pilha.h: Define a estrutura da pilha e as funções para manipulação da pilha (criar, destruir, empilhar, desempilhar, verificar o topo, etc.).

pilha.c: Implementa as funções definidas em pilha.h.

torre.c: Contém a implementação do jogo, incluindo a lógica para movimentar os discos entre as torres, verificar a validade dos movimentos e exibir o estado do jogo.


- Funcionalidades:
  
Criação de Pilha: As pilhas são criadas dinamicamente para armazenar os discos.

Movimento de Discos: O jogador pode mover os discos entre as torres, desde que a jogada seja válida.

Validação de Movimentos: O jogo verifica se o movimento solicitado é válido, ou seja, se o disco da torre origem é menor que o disco da torre destino ou se a torre destino está vazia.

Exibição das Torres: Após cada movimento, o estado das torres é impresso, mostrando a posição dos discos.

Finalização do Jogo: O jogo é concluído quando todos os discos estão na torre de destino. O número de movimentos realizados é então exibido.


- Tecnologias Utilizadas:


Linguagem: C

Estruturas de Dados: Pilha (implementada com ponteiros)


-Como Executar


1. Clone o repositório: git clone <url-do-repositorio>

2. cd <diretorio-do-repositorio>

3. Compile o código: gcc pilha.c torre.c -o torre

4. Execute o programa: ./torre
   
Durante o jogo, insira o número de discos e as jogadas no formato origem,destino para mover os discos.

