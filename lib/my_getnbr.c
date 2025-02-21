/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_getnbr.c
*/

#include <limits.h>

long my_limits(long res)
{
    if (res < INT_MIN || res > INT_MAX) {
        res = 0;
    }
    return(res);
}
int my_getnbr(char const *str)
{
    int i = 0;
    int pos = 0;
    long res = 0;

    while ((str[pos] < 48 || str[pos] > 57) && str[pos] != '\0') {
        pos = pos + 1;
    }
    i = pos;
    while ((str[i] >= 48 && str[i] <= 57)) {
        res = res * 10 + (str[i] - 48);
        i = i + 1;
    }
    res = my_limits(res);
    return (res);
}