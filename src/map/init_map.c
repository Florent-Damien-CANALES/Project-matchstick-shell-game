/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** init_map.c
*/

#include "../../include/matchstick.h"
#include <stdlib.h>
#include <stdio.h>

void pipe(game_t *game, int len, int col)
{
    int col_start = 1;
    int pos = 1;
    int line = len - 2;
    int matches = col - 2;

    while (line != 0) {
        for (int rep = 0; rep < matches; rep = rep + 1) {
            game->map[line][pos] = '|';
            pos = pos + 1;
        }
        line = line - 1;
        matches = matches - 2;
        col_start = col_start + 1;
        pos = col_start;
    }
}

void fill_map(game_t *game, int len, int col)
{
    for (int i = 0; i < col; i = i + 1)
        game->map[0][i] = '*';
    for (int i = 0; i < (len - 1); i = i + 1)
        game->map[i][0] = '*';
    for (int i = 0; i < len; i = i + 1)
        game->map[i][col - 1] = '*';
    for (int i = 0; i < col; i = i + 1)
        game->map[len - 1][i] = '*';
    pipe(game, len, col);
}
void init_map(game_t *game)
{
    int len = game->size + 2;
    int col = 3;
    int pos = 0;

    game->map = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; i < (game->size - 1); i = i + 1)
        col = col + 2;
    while (pos < len) {
        game->map[pos] = malloc(sizeof(char) * (col + 1));
        for (int i = 0; i < col; i = i + 1)
            game->map[pos][i] = ' ';
        game->map[pos][col] = '\0';
        pos = pos + 1;
    }
    game->map[pos] = NULL;
    fill_map(game, len, col);
}