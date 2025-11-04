#include <stdio.h>
#include <stdlib.h>

#include "tile.h"

#define TAM_Y 400
#define TAM_X 800
#define LINHAS 8
#define COLUNAS 20

void initializeTiles(Tile grid[COLUNAS][LINHAS]);
void initializePlayers(Jogador jogadores[2]);
int checkTiles(Tile grid[COLUNAS][LINHAS]);
int checkPlayers(Jogador jogadores[2]);
void imprimeGrid(Tile grid[COLUNAS][LINHAS]);
void printSpace();
void initializeGame(Tile grid[COLUNAS][LINHAS], Jogador jogadores[2],
                    int* largura, int* altura);
int checkGuess(int x, int y, Tile grid[COLUNAS][LINHAS], Jogador* jogador);
void printStats(Jogador jogador, int i);