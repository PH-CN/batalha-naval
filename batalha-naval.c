#include <stdio.h>


int main() {

    int tabuleiro[10][10];
    int tamtabuleiro = 10, tamnavio = 3;
    int horizontalLinha = 5, horizontalColuna = 5; // índices da casa inicial do navio
    int verticalLinha = 2, verticalColuna = 8; // índices da casa inicial do navio
    int diagonal1Linha = 1, diagonal1Coluna = 2;
    int diagonal2Linha = 7, diagonal2Coluna = 2;

    // Preenche o tabuleiro inteiro com 0s
    for(int i = 0; i < 10; i++) {
        for(int n = 0; n < 10; n++) {
            tabuleiro[i][n] = 0;
        }
    }

    if(horizontalColuna + tamnavio > tamtabuleiro) {
        printf("O navio horizontal está fora do tabuleiro!\n");
        return 1;
    }

    if(verticalLinha + tamnavio > tamtabuleiro) {
        printf("O navio vertical está fora do tabuleiro!\n");
        return 1;
    }

    if(diagonal1Linha + tamnavio > tamtabuleiro || diagonal1Coluna + tamnavio > tamtabuleiro) {
        printf("O navio diagonal 1 está fora do tabuleiro!\n");
        return 1;
    }

    if(diagonal2Linha + tamnavio > tamtabuleiro || diagonal2Coluna - (tamnavio - 1) < 0) {
        printf("O navio diagonal 2 está fora do tabuleiro!\n");
        return 1;
    }

    // Posicionando os navios horizontal e vertical no tabuleiro
    for (int i = 0; i < tamnavio; i++) {
        tabuleiro[horizontalLinha][horizontalColuna + i] = 3;     // navio horizontal
        if(tabuleiro[verticalLinha + i][verticalColuna] != 0) {     // verificação de sobreposição
            printf("Sobreposição detectada! (vertical)\n");
            return 1;
        }
        tabuleiro[verticalLinha + i][verticalColuna] = 3;      // navio vertical
    }

    // posicionando os navios diagonais no tabuleiro
    for (int i = 0; i < tamnavio; i++) {
        if(tabuleiro[diagonal1Linha + i][diagonal1Coluna + i] != 0) {
            printf("Sobreposição detectada! (diagonal 1)\n");
            return 1;
        }
        tabuleiro[diagonal1Linha + i][diagonal1Coluna + i] = 3;
    }

    for (int i = 0; i < tamnavio; i++) {
        if(tabuleiro[diagonal2Linha + i][diagonal2Coluna - i] != 0) {
            printf("Sobreposição detectada! (diagonal 2)\n");
            return 1;
        }
        tabuleiro[diagonal2Linha + i][diagonal2Coluna - i] = 3;
    }

    // Imprime o tabuleiro
    for(int i = 0; i < 10; i++) {
        for(int n = 0; n < 10; n++) {
            printf("%d ", tabuleiro[i][n]);
        }
    printf("\n");
    }

    return 0;
}