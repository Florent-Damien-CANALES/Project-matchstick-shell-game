/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** check_win.c
*/

#include "../../../include/matchstick.h"
#include <stdio.h>

int check_win(game_t *game)
{
    int win = 1;
    int line = 0;

    while (game->map[line] != NULL) {
        for (int i = 0; game->map[line][i] != '\0'; i = i + 1) {
            if (game->map[line][i] == '|')
                win = 0;
        }
        line = line + 1;
    }
    if (win == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        game->status = 1;
    } else {
        my_putchar('\n');
    }
    return (win);
}