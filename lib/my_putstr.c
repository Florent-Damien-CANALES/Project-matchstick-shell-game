/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_putstr.c
*/

#include "../include/matchstick.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int b = 0;

    while (str[b] != '\0'){
        my_putchar(str[b]);
        b = b + 1;
    }
    return (0);
}