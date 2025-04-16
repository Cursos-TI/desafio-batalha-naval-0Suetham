#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Sobrepõe a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int offset = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + i - offset;
            int coluna = origemColuna + j - offset;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Preenche matriz cone
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Preenche matriz cruz
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Preenche matriz octaedro (losango)
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade[TAM_HAB][TAM_HAB];

    // Inicializa tabuleiro com água
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona navios (exemplo fixo)
    for (int j = 0; j < 3; j++) tabuleiro[0][j] = NAVIO;        // Horizontal
    for (int i = 2; i < 5; i++) tabuleiro[i][5] = NAVIO;        // Vertical
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][6 + i] = NAVIO; // Diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][3 - i] = NAVIO; // Diagonal secundária

    exibirTabuleiro(tabuleiro);

    // Aplica habilidade: Cone
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);
    printf("\nHabilidade: Cone em (2,2)\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidade: Cruz
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    printf("\nHabilidade: Cruz em (5,5)\n");
    exibirTabuleiro(tabuleiro);

    // Aplica habilidade: Octaedro
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 7);
    printf("\nHabilidade: Octaedro em (7,7)\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
