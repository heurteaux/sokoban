/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** menu.c
*/

#include "../setup_ncurses.h"
#include <ncurses.h>

void start_menu()
{
    int key = 0;

    setup_term();
    while (key != 27) {

        key = getch();
        clear();
        refresh();
    }
}
