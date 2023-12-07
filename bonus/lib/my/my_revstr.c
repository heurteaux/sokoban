/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task03
*/

#include "my.h"

__attribute__((unused)) char *my_revstr(char *str)
{
    char holder;
    int len = my_strlen(str) - 1;

    for (int i = 0; i < len / 2; i++) {
        holder = str[i];
        str[i] = str[len - i];
        str[len - i] = holder;
    }
    return str;
}
