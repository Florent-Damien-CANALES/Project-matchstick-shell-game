/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main.c
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    return (matchstick(ac, av));
}