/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main.c
*/

#include "internal_functions/help_menu.h"
#include "internal_functions/game_logic/game.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (is_help_menu_requested(argc, argv))
        return help_menu(argc, argv);
    start_game(argv);
    return 0;
}
