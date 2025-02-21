/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** free_tab.c
*/

#include <stdlib.h>

char **free_tab(char **tab)
{
    int line = 0;

    while (tab[line] != NULL) {
        free(tab[line]);
        line = line + 1;
    }
    free(tab);
}