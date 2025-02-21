/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick.c
*/

#include "../include/matchstick.h"
#include <stdlib.h>
#include <time.h>

int init_data(game_t *game, int ac, char **av)
{
    if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
        return (84);
    game->size = my_getnbr(av[1]);
    game->remove = my_getnbr(av[2]);
    if (game->size < 2 || game->size > 99 || game->remove <= 0)
        return (84);
    init_map(game);
    return (0);
}

int matchstick(int ac, char **av)
{
    int res;
    game_t *game = malloc(sizeof(game_t));
    srand(time(NULL));
    if (init_data(game, ac, av) == 84)
        return (84);
    game_loop(game);
    res = game->status;
    game->map = free_tab(game->map);
    free(game);
    return (res);
}