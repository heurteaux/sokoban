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
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
}
