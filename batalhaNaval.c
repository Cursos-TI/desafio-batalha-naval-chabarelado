#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades Especiais com Matrizes

#define Coluna 10
#define Linha 10
#define Navio 3
#define Cone 4 
#define Octaedro 5
#define Cruz 6


void ImprimeTabuleiro(int tabuleiro[Coluna][Linha]) {   
    char linha[Coluna] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Vetor que representa as colunas

    // Imprime o tabuleiro:
    printf("\n\t<-- TABULEIRO BATALHA NAVAL -- >\n\n");
    printf("    ");
    
    // Imprime as colunas em ordem alfabetica:
    for (int i = 0; i < Linha; i++) {
        printf(" %c ", linha[i]);
    }

    // Elemento visual para facilitar a visualização do tabuleiro:
    printf("\n_________________________________\n");
    
    // Imprime as linhas e o tabuleiro com os navios posicionados:
    for (int i = 0; i < Linha; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < Coluna; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void ImprimeOctaedro(int tabuleiro[Linha][Coluna], int linha, int coluna) {
    // Atribuindo Octaedro:
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2 || (i == 1 && j >= 2 - i && j <= 2 + i) || (i == 2 && j >= 2 - i && j <= 2 + i) || (i == 3 && j <= i && j > 0))
            {   
                /*
                - Cond1: Se J == 2: Preenche com 2.
                - Cond2: Ou se I for indice 1 e J for igual a (1,2,3) -> [2 - 1 = 1 | 2 + 1 = 3] -> Range de (1 a 3)
                - Cond3: Ou se I for indice 2 e J for igual a (0,1,2,3) -> [2 - 2 = 0| 2 + 2 = 4] - Range de (0 a 4)
                - Cond4: Ou se I for indice 3 e J for menor que I e maior que 0.
                */
                if (tabuleiro[i + linha][j + coluna] != 0) {
                    tabuleiro[i + linha][ j + coluna] = 1; // Se o elemento ja estiver preenchido recebe o valor 1
                } else {
                    tabuleiro[i + linha][ j + coluna] = Octaedro; // Se o elemento não estiver preenchido recebe o valor 5
                }
            }
        }
    }
}

void ImprimeCone(int tabuleiro[Linha][Coluna], int linha, int coluna) {
    // Atribuindo Cone:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                if (tabuleiro[i + linha][j + coluna] != 0) { 
                    tabuleiro[i + linha][ j + coluna] = 1; // Se o elemento ja estiver preenchido recebe o valor 1
                } else {
                    tabuleiro[i + linha][ j + coluna] = Cone; // Se o elemento não estiver preenchido recebe o valor 4
                }
            }
        }
    }
}

void ImprimeCruz (int tabuleiro[Linha][Coluna], int linha, int coluna) {
    // Atribuindo o Cruz:
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2 || i == 2) { // Se J for igual a 2 ou I igual a 2 o elemento é preenchido.
                if (tabuleiro[i + linha][j + coluna] != 0) { 
                    tabuleiro[i + linha][ j + coluna] = 1; // Se o elemento ja estiver preenchido recebe o valor 1
                } else {
                    tabuleiro[i + linha][ j + coluna] = Cruz; // Se o elemento não estiver preenchido recebe o valor 6
                }
            }
        }
    } 
}

void ImprimeNavio (int tabuleiro[Linha][Coluna], int linha, int coluna, int posicao){
    for (int i = 0; i < Navio; i++)
    {
        if (posicao == 1) { // Imprime na Horizontal
            if (tabuleiro[linha][coluna + i] != 0) {  // Se o elemento estiver preenchido recebe 1
                tabuleiro[linha][coluna + i] = 1; 
            } else {
                tabuleiro[linha][coluna + i] = Navio;  // Se o elemento não estiver preenchido recebe 3
            }
        } else if (posicao == 2) { // Imprime na Vertical
            if (tabuleiro[linha + i][coluna] != 0) {  // Se o elemento estiver preenchido recebe 1
                tabuleiro[linha + i][coluna] = 1; 
            } else {
                tabuleiro[linha + i][coluna] = Navio;  // Se o elemento não estiver preenchido recebe 3
            }
        } else if (posicao == 3) { // Imprime na Diagonal Esquerda
            if (tabuleiro[linha + i][coluna + i] != 0) {  // Se o elemento estiver preenchido recebe 1
                tabuleiro[linha + i][coluna + i] = 1; 
            } else {
                tabuleiro[linha + i][coluna + i] = Navio;  // Se o elemento não estiver preenchido recebe 3
            }
        } else if (posicao == 4) { // Imprime na Diagonal Direita
            if (tabuleiro[linha - i][coluna + i] != 0) {  // Se o elemento estiver preenchido recebe 1
                tabuleiro[linha - i][coluna + i] = 1; 
            } else {
                tabuleiro[linha - i][coluna + i] = Navio; // Se o elemento não estiver preenchido recebe 3
            }
        }
    }
}

int main() {
    // Variáveis:
    int colunaH = 7, linhaH = 6; // Posiciona o navio na Horizontal.
    int colunaV = 7, linhaV = 2; // Posiciona o navio na Vertical.
    int colunaD1 = 1, linhaD1 = 7; // Posiciona o navio na diagonal Esquerda.
    int colunaD2 = 1, linhaD2 = 2; // Posiciona o navio na diagonal Direita.
    int colunaO = 5, linhaO= 5; // Posiciona o octaedro.
    int colunaC = 3, linhaC = 1; // Posiciona a cruz.
    int colunaCo = 1, linhaCo = 7; // Posiciona o cone.

    //Matriz do tabuleiro (10x10 inicializado com 0:
    int tabuleiro[Linha][Coluna] = {0};
    
    // Atribui e imprime os elementos de Navios e habilidades:
    ImprimeCone(tabuleiro, linhaCo, colunaCo);
    ImprimeCruz(tabuleiro, linhaC,colunaC);
    ImprimeOctaedro(tabuleiro, linhaO,colunaO);
    ImprimeNavio(tabuleiro,linhaH, colunaH, 1);
    ImprimeNavio(tabuleiro, linhaV, colunaV, 2);
    ImprimeNavio(tabuleiro, linhaD1, colunaD1, 3);
    ImprimeNavio(tabuleiro,linhaD2, colunaD2, 4);
    ImprimeTabuleiro(tabuleiro);

    return 0;
}
