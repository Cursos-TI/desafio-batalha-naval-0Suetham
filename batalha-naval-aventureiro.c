#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
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

    // Navio 1 - Horizontal (linha 0, colunas 0 a 2)
    for (int j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[0][j] = OCUPADO;
    }

    // Navio 2 - Vertical (coluna 5, linhas 2 a 4)
    for (int i = 2; i < 2 + TAM_NAVIO; i++) {
        tabuleiro[i][5] = OCUPADO;
    }

    // Navio 3 - Diagonal principal (início em [6][6])
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[6 + i][6 + i] = OCUPADO;
    }

    // Navio 4 - Diagonal secundária (início em [6][3])
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[6 + i][3 - i] = OCUPADO;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval - Nível Aventureiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
