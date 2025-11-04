#include "functions.h"

void initializeTiles(Tile grid[COLUNAS][LINHAS]) {
    for (int i = 0; i < COLUNAS; i++) {
        for (int j = 0; j < LINHAS; j++) {
            grid[i][j].investigado = 0;
            grid[i][j].premio = rand() % 11;
        }
    }
}

void initializePlayers(Jogador jogadores[2]) {
    for (int i = 0; i < 2; i++) {
        jogadores[i].pontuacao = 0;
        jogadores[i].vidas = 3;
    }
}

int checkTiles(Tile grid[COLUNAS][LINHAS]) {
    for (int i = 0; i < COLUNAS; i++) {
        for (int j = 0; j < LINHAS; j++) {
            if (grid[i][j].investigado == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int checkPlayers(Jogador jogadores[2]) {
    for (int i = 0; i < 2; i++) {
        if (jogadores[i].vidas == 0) {
            return i + 1;
        }
    }

    return 0;
}

void imprimeGrid(Tile grid[COLUNAS][LINHAS]) {
    for (int i = 0; i < COLUNAS; i++) {
        printf("\t%d", i);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%d\t", i);
        for (int j = 0; j < COLUNAS; j++) {
            if (grid[j][i].investigado == 0) {
                printf("[%d]", grid[j][i].premio);
            } else {
                printf("[*%d]", grid[j][i].premio);
            }
            printf("\t");
        }

        printf("\n");
    }
}

void printSpace() {
    for (int i = 0; i < 100; i++) {
        printf("-");
    }
    printf("\n");
}

void initializeGame(Tile grid[COLUNAS][LINHAS], Jogador jogadores[2],
                    int* largura, int* altura) {
    initializePlayers(jogadores);
    initializeTiles(grid);

    *largura = TAM_X / COLUNAS;
    *altura = TAM_Y / LINHAS;
}

int checkGuess(int x, int y, Tile grid[COLUNAS][LINHAS], Jogador* jogador) {
    if (x > COLUNAS || y > LINHAS || x < 0 || y < 0) {
        printf("Celula nao existente, -1 vida\n");
        jogador->vidas--;
        return -1;
    } else if (grid[x][y].investigado == 0) {
        grid[x][y].investigado = 1;
        jogador->pontuacao += grid[x][y].premio;
        printf("Celula nao investigada, +%d pontos\n", grid[x][y].premio);
        return 0;
    } else {
        printf("Celula ja investigada, -1 vida\n");
        jogador->vidas--;
        return 1;
    }
}

void printStats(Jogador jogador, int i) {
    printf("Pontuacao do Jogador %d = %d\n", i + 1, jogador.pontuacao);
    printf("Vidas do Jogador %d = %d\n", i + 1, jogador.vidas);
}