#include <stdio.h>

#define TAM 10      // Tamanho do tabuleiro 10x10
#define NAVIO 3     // Valor que representa o navio no tabuleiro
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];

    // 1. Inicializar tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Navios representados como vetores (valores 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais definidas no código:
    int linhaH = 2, colunaH = 1; // Navio horizontal começa em (2,1)
    int linhaV = 5, colunaV = 7; // Navio vertical começa em (5,7)

    // 3. Validação do navio horizontal
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // 4. Validação do navio vertical
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical ultrapassa o limite do tabuleiro!\n");
        return 1;
    }

    // 5. Verificação de sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0 ||
            tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: navios se sobrepõem!\n");
            return 1;
        }
    }

    // 6. Posicionar navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // 7. Posicionar navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // 8. Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
