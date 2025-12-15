#include <stdio.h>

#define TAM 10
#define NAV 3
#define HAB 5

int main() {

    int tabuleiro[TAM][TAM];
    int HabCone[HAB][HAB];
    int HabCruz[HAB][HAB];
    int HabOct[HAB][HAB];
    int horizontalLinha = 5, horizontalColuna = 5; // índices da casa inicial do navio
    int verticalLinha = 1, verticalColuna = 8; // índices da casa inicial do navio
    int diagonal1Linha = 1, diagonal1Coluna = 2; // índices da casa inicial do navio
    int diagonal2Linha = 7, diagonal2Coluna = 2; // índices da casa inicial do navio
    int centroHab = 2;
    int coneLinha = 2, coneColuna = 2; // indice de origem do ataque
    int cruzLinha = 4, cruzColuna = 6; // indice de origem do ataque
    int octLinha  = 7, octColuna  = 3; // indice de origem do ataque

    // Preenche o tabuleiro inteiro com 0s
    for(int i = 0; i < 10; i++) {
        for(int n = 0; n < 10; n++) {
            tabuleiro[i][n] = 0;
        }
    }

    // Criação do cone
    printf("*** CONE ***\n");
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            if(i <= 2) {
                if(j >= centroHab - i && j <= centroHab + i) {
                    HabCone[i][j] = 1;
                    printf("%d ", HabCone[i][j]);
                } else {
                    HabCone[i][j] = 0;
                    printf("%d ", HabCone[i][j]);
                }
            } else {
                HabCone[i][j] = 0;
                printf("%d ", HabCone[i][j]);
                
            }
        }
        printf("\n");
    }

    printf("\n");

    // Criação da cruz
    printf("*** CRUZ ***\n");
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {
            if(i == centroHab|| j == centroHab) {
                HabCruz[i][j] = 1;
                printf("%d ", HabCruz[i][j]);
            } else {
                HabCruz[i][j] = 0;
                printf("%d ", HabCruz[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");

    int raio = 2;
    int distancia;


    // Criação do Octaedro
    printf("*** OCTAEDRO ***\n");
    for(int i = 0; i < HAB; i++) {
        for(int j = 0; j < HAB; j++) {

            if (i <= centroHab) {
                distancia = centroHab - i;
            } else {
                distancia = i - centroHab;
            }

            if (j >= centroHab - (raio - distancia) && j <= centroHab + (raio - distancia)) {
                HabOct[i][j] = 1;
                printf("%d ", HabOct[i][j]);
            } else {
                HabOct[i][j] = 0;
                printf("%d ", HabOct[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");

    if(horizontalColuna + NAV > TAM) {
        printf("O navio horizontal está fora do tabuleiro!\n");
        return 1;
    }

    if(verticalLinha + NAV > TAM) {
        printf("O navio vertical está fora do tabuleiro!\n");
        return 1;
    }

    if(diagonal1Linha + NAV > TAM || diagonal1Coluna + NAV > TAM) {
        printf("O navio diagonal 1 está fora do tabuleiro!\n");
        return 1;
    }

    if(diagonal2Linha + NAV > TAM || diagonal2Coluna - (NAV - 1) < 0) {
        printf("O navio diagonal 2 está fora do tabuleiro!\n");
        return 1;
    }

    // Posicionando os navios horizontal e vertical no tabuleiro
    for (int i = 0; i < NAV; i++) {
        tabuleiro[horizontalLinha][horizontalColuna + i] = 3;     // navio horizontal
        if(tabuleiro[verticalLinha + i][verticalColuna] != 0) {     // verificação de sobreposição
            printf("Sobreposição detectada! (vertical)\n");
            return 1;
        }
        tabuleiro[verticalLinha + i][verticalColuna] = 3;      // navio vertical
    }

    // posicionando os navios diagonais no tabuleiro
    for (int i = 0; i < NAV; i++) {
        if(tabuleiro[diagonal1Linha + i][diagonal1Coluna + i] != 0) {
            printf("Sobreposição detectada! (diagonal 1)\n");
            return 1;
        }
        tabuleiro[diagonal1Linha + i][diagonal1Coluna + i] = 3;
    }

    for (int i = 0; i < NAV; i++) {
        if(tabuleiro[diagonal2Linha + i][diagonal2Coluna - i] != 0) {
            printf("Sobreposição detectada! (diagonal 2)\n");
            return 1;
        }
        tabuleiro[diagonal2Linha + i][diagonal2Coluna - i] = 3;
    }

    // Aplicando o ataque de cone ao tabuleiro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int linhaTab = coneLinha - centroHab + i;
            int colunaTab = coneColuna - centroHab + j;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (HabCone[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }
}
    // Aplicando o ataque de cruz ao tabuleiro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int linhaTab = cruzLinha - centroHab + i;
            int colunaTab = cruzColuna - centroHab + j;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (HabCruz[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 6;
            }
        }
    }
}
    // Aplicando o ataque de octaedro ao tabuleiro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int linhaTab = octLinha - centroHab + i;
            int colunaTab = octColuna - centroHab + j;

            if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                if (HabOct[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 7;
            }
        }
    }
}

    // Imprime o tabuleiro
    printf("TABULEIRO (os ataques sobrepõem os navios anteriormente colocados)\n");
    for(int i = 0; i < 10; i++) {
        for(int n = 0; n < 10; n++) {
            printf("%d ", tabuleiro[i][n]);
        }
    printf("\n");
    }

    return 0;
}