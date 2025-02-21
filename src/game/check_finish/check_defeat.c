/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** check_defeat.c
*/

#include "../../../include/matchstick.h"
#include <stdio.h>

int check_defeat(game_t *game)
{
    int defeat = 1;
    int line = 0;

    while (game->map[line] != NULL) {
        for (int i = 0; game->map[line][i] != '\0'; i = i + 1) {
            if (game->map[line][i] == '|')
                defeat = 0;
        }
        line = line + 1;
    }
    if (defeat == 1) {
        my_putstr("You lost, too bad...\n");
        game->status = 2;
    } else {
        my_putchar('\n');
    }
    return (defeat);
}