/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** game.c
*/

#include "../../include/matchstick.h"

int game_loop(game_t *game)
{
    int i = 0;

    print_map(game);
    my_putchar('\n');
    while (i == 0) {
        if (player_turn(game) == 0) {
            game->status = 0;
            return (0);
        }
        if (check_defeat(game) == 1)
            return (0);
        ai_turn(game);
        if (check_win(game) == 1)
            return (0);
    }
}