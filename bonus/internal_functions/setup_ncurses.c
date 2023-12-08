/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** setup_ncurses.c
*/

#include <ncurses.h>

void setup_term(void)
{
    initscr();
    start_color();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    for (short i = 0; i < 256; i++) {
        init_pair(i + 1, i, i);
    }
}
