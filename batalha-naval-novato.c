#include <stdio.h>

#define TAM_TABULEIRO 5
#define OCUPADO 3
#define AGUA 0

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona um navio horizontalmente (linha 1, colunas 1 a 3)
    for (int j = 1; j <= 3; j++) {
        tabuleiro[1][j] = OCUPADO;
    }

    // Posiciona um navio verticalmente (coluna 3, linhas 2 a 4)
    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][3] = OCUPADO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval - Nível Novato:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}