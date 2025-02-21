/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_strcmp.c
*/

#include <stdio.h>

int my_strlen(char *buffer)
{
    int len = 0;

    while (buffer[len] != '\0' && buffer[len] != '\n') {
        len  = len + 1;
    }
    return (len);
}

int my_strcmp(char *str1, char* str2)
{
    int pos;
    int col = 0;

    for (pos = 0 ; str1[pos] == 32 || str1[pos] == 9; pos = pos + 1);
    if ((my_strlen(str1)) != (my_strlen(str2)))
        return (0);
    while (str1[pos] != '\0' && str1[pos] != '\n'
    && str1[pos] != 9 && str1[pos] != ' ') {
        if (str1[pos] != str2[col])
            return (0);
        pos = pos + 1;
        col = col + 1;
    }
    return (1);
}