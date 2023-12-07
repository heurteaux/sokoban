/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** task01
*/

#include "my.h"

__attribute__((unused)) void my_swap(int *a, int *b)
{
    int holder;

    holder = *a;
    *a = *b;
    *b = holder;
}
