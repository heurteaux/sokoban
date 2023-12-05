/*
** EPITECH PROJECT, 2023
** day03
** File description:
** task01
*/
#include <unistd.h>

int my_print_alpha(void)
{
    for (unsigned int i = 97; i <= 122; i++) {
        write(1, &i, 1);
    }
    return 0;
}
