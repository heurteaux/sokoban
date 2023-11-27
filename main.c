/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main.c
*/

#include "includes/internal_functions.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (is_help_menu_requested(argc, argv))
        return help_menu(argc, argv);
    start_sokoban(argv);
    return 0;
}
