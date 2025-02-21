/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** player_turn.c
*/

#include "../../../include/matchstick.h"

void display_move(game_t *game)
{
    my_putstr("Player removed ");
    my_put_nbr(game->p_rm);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->p_line);
    my_putchar('\n');
}

int player_turn(game_t *game)
{
    my_putstr("Your turn:\n");
    if (line_input(game) == 0)
        return (0);
    if (matches_input(game) == 0)
        return (0);
    remove_matches(game, game->p_line, game->p_rm);
    display_move(game);
    print_map(game);
    return (1);
}