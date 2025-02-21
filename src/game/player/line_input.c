/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** line_input.c
*/

#include "../../../include/matchstick.h"
#include <stdio.h>

int empty(game_t *game)
{
    for (int i = 0; game->map[game->p_line][i] != '\0'; i = i + 1) {
        if (game->map[game->p_line][i] == '|')
            return (1);
    }
    return (0);
}

int line_input(game_t *game)
{
    char *input = NULL;
    size_t n = 0;
    int status = 0;

    while (status == 0) {
        status = 1;
        my_putstr("Line: ");
        if (getline(&input, &n, stdin) < 0)
            return (0);
        if (my_str_isnum(input) == 0 || my_strcmp(input, "\n") == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            status = 0;
        }
        game->p_line = my_getnbr(input);
        if (status == 1 && (game->p_line == 0 || game->p_line > game->size)
        || empty(game) == 0) {
            my_putstr("Error: this line is out of range\n");
            status = 0;
        }
    }
    return (1);
}