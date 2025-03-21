#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Variáveis:
    int colunaH = 7, linhaH = 2; // Posiciona o navio na horizontal.
    int colunaV = 2, linhaV = 7; // Posiciona o navio na vertical.
    // Vetores incializados (Arrays):
    int navioH[3] = {3,3,3}; 
    int navioV[3] = {3,3,3};
    int linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Matriz do tabuleiro (10x10):
    int tabuleiro[10][10];

    // Incializando o tabuleiro:
    for (int i = 0; i < 10; i++)
    {   
        for(int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;// Atribui um valor em cada coluna e linha da matriz
        }
    }

    // Atribuindo o navio da linha horizontal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaH][colunaH + i] = navioH[2]; // Adiciona o valor 3 nas posições em que o navio se encontra
    }  

    // Atribuindo o navio da coluna vertical:
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaV + i][colunaV] = navioV[2]; // Adiciona o valor 3 nas posições em que o navio se encontra
    }  
  
    // Imprime o tabuleiro:
    printf("\n\t<-- TABULEIRO BATALHA NAVAL -- >\n\n");
    printf("\t");
    
    // Imprime as colunas em ordem alfabetica:
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", linha[i]);
    }

    // Elemento visual para facilitar a visualização do tabuleiro:
    printf("\n\t_____________________________\n");
    
    // Imprime as linhas e o tabuleiro com os navios posicionados:
    for (int i = 0; i < 10; i++) {
        printf("%d |\t", i);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
