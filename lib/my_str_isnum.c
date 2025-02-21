/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_str_isnum.c
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int res = 1;
    while (str[i] != '\n' && str[i] != '\0') {
        if ('0' > str[i] || str[i] > '9') {
            res = 0;
        }
        i = i + 1;
    }
    return (res);
}