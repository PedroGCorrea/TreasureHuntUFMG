#include <time.h>

#include "src/functions.h"



int main() {
    srand(time(NULL));
    Tile grid[COLUNAS][LINHAS];
    Jogador jogadores[2];
    int largura_tile;
    int altura_tile;
    int turno = 0;

    initializeGame(grid, jogadores, &largura_tile, &altura_tile);

    while (checkTiles(grid) && !checkPlayers(jogadores)) {
        int x, y;

        printf("Vez do jogador [%d]:\n", turno + 1);
        scanf("%d %d", &x, &y);

        if (x == -1 && y == -2) {
            break;
        }
        int colunaCore = x / largura_tile;
        int linhaCore = y / altura_tile;

        printf("Atingido: [%d] , [%d] \n", colunaCore, linhaCore);

        checkGuess(colunaCore, linhaCore, grid, &jogadores[turno]);

        printSpace();

        printStats(jogadores[turno], turno);

        printSpace();

        if (turno == 0) {
            turno = 1;
        } else {
            turno = 0;
        }
    }
    printSpace();
    printf("FIM\n\n");

    if (checkPlayers(jogadores)) {
        printf("O JOGADOR [%d] VENCEU !!!\n", checkPlayers(jogadores));
    } else {
        if (jogadores[0].pontuacao > jogadores[1].pontuacao) {
            printf("O JOGADOR [0] VENCEU !!!\n");
        } else if (jogadores[1].pontuacao > jogadores[0].pontuacao) {
            printf("O JOGADOR [1] VENCEU !!!\n");
        } else {
            printf("EMPATE\n");
        }
    }

    imprimeGrid(grid);
    return 0;
}