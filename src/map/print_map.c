/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** print_map.c
*/

#include "../../include/matchstick.h"
#include <stdio.h>

void print_map(game_t *game)
{
    for (int i = 0; game->map[i] != NULL; i = i + 1) {
        my_putstr(game->map[i]);
        my_putchar('\n');
    }
}