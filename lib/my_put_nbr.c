/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_put_nbr.c
*/

#include "../include/lib.h"
#include <stdio.h>

int my_put_nbr(int nb)
{
    int n = 0;
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb > 9) {
        n = nb %10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(n + 48);
    } else if (nb < 0) {
        nb = nb * -1;
        my_putchar(45);
        my_put_nbr(nb);
    }
    return(0);
}