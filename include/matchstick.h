/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include "lib.h"

typedef struct game{
    char **map;
    int remove;
    int size;
    int status;
    int p_rm;
    int p_line;
}game_t;

int main(int ac, char **av);
int matchstick(int ac, char **av);
void init_map(game_t *game);
void print_map(game_t *game);
char **free_tab(char **tab);
int check_defeat(game_t *game);
int check_win(game_t *game);
void remove_matches(game_t *game, int line, int nb_remove);
int game_loop(game_t *game);
int player_turn(game_t *game);
int line_input(game_t *game);
int matches_input(game_t *game);
void ai_turn(game_t *game);

#endif