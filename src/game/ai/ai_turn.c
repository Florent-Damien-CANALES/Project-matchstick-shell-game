/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** ai_turn.c
*/

#include "../../../include/matchstick.h"
#include <stdlib.h>

void display_aimove(game_t *game, int nb_rm, int line)
{
    my_putstr("AI removed ");
    my_put_nbr(nb_rm);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int count_matches(game_t *game, int line)
{
    int pos = 3;
    int nb = 0;

    for (int i = 0; i < (game->size - 1); i = i + 1)
        pos = pos + 2;
    for (pos; game->map[line][pos] != '|'; pos = pos - 1);
    for (pos; game->map[line][pos] == '|'; pos = pos - 1)
        nb = nb + 1;
    return (nb);
}

int check_line(game_t *game, int line)
{
    for (int i = 0; game->map[line][i] != '\0'; i = i + 1) {
        if (game->map[line][i] == '|')
            return (1);
    }
    return (0);
}

int chose_line(game_t *game)
{
    int line = 0;
    int status = 0;

    while (status == 0) {
        status = 1;
        line = (rand() % game->size) + 1;
        if (check_line(game, line) == 0)
            status = 0;
    }
    return (line);
}

void ai_turn(game_t *game)
{
    int line = chose_line(game);
    int nb_match = count_matches(game, line);
    int nb_rm = 0;

    if (nb_match > game->remove) {
        nb_rm = ((rand() % game->remove) + 1);
    } else {
        nb_rm = ((rand() % nb_match) + 1);
    }
    my_putstr("AI's turn...\n");
    display_aimove(game, nb_rm, line);
    remove_matches(game, line, nb_rm);
    print_map(game);
}