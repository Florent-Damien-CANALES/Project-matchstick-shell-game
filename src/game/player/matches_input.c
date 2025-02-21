/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matches_input.c
*/

#include "../../../include/matchstick.h"
#include <stdio.h>

int count_match(game_t *game)
{
    int pos = 3;
    int nb = 0;

    for (int i = 0; i < (game->size - 1); i = i + 1)
        pos = pos + 2;
    for (pos; game->map[game->p_line][pos] != '|'; pos = pos - 1);
    for (pos; game->map[game->p_line][pos] == '|'; pos = pos - 1)
        nb = nb + 1;
    return (nb);
}

int check_input(game_t *game)
{
    int status = 0;
    int nb_matches = count_match(game);

    if (game->p_rm <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (game->p_rm > game->remove) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->remove);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (game->p_rm > nb_matches) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int matches_input(game_t *game)
{
    char *input = NULL;
    size_t n = 0;
    int status = 0;
    int i;

    while (status == 0) {
        status = 1;
        count_match(game);
        my_putstr("Matches: ");
        i = getline(&input, &n, stdin);
        if (i < 0)
            return (0);
        if (my_str_isnum(input) == 0 || my_strcmp(input, "\n") == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            status = 0;
        }
        game->p_rm = my_getnbr(input);
        if (status != 0 && check_input(game) == 1)
            status = 0;
    }
    return (1);
}