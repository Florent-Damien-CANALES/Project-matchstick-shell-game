/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** remove_matches.c
*/

#include "../../include/matchstick.h"

void remove_matches(game_t *game, int line, int nb_remove)
{
    int col = 2;

    for (int i = 0; i < (game->size - 1); i = i + 1)
        col = col + 2;
    for (col; game->map[line][col] != '|'; col = col - 1);
    for (int i = 0; i < nb_remove; i = i + 1) {
        game->map[line][col] = ' ';
        col = col - 1;
    }
}