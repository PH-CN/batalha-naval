#include <stdio.h>


main() {

    int tabuleiro[10][10];
    int tamtabuleiro = 10, tamnavio = 3;
    int horizontalLinha = 3, horizontalColuna = 0; // índices da casa inicial do navio
    int verticalLinha = 7, verticalColuna = 7; // índices da casa inicial do navio

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

    // Posicionando os navios no tabuleiro
    for (int i = 0; i < tamnavio; i++) {
        tabuleiro[horizontalLinha][horizontalColuna + i] = 3;     // navio horizontal
        if(tabuleiro[verticalLinha + i][verticalColuna] != 0) {     // verificação de sobreposição
            printf("Sobreposição detectada!\n");
            return 1;
        }
        tabuleiro[verticalLinha + i][verticalColuna] = 3;      // navio vertical
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