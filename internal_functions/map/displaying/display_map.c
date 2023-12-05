/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** display_map.c
*/

#include <ncurses.h>
#include "../../../data_structs/map.h"
#include "../../../lib/my.h"

__attribute__((unused)) void print_map(map_t map)
{
    for (int i = 0; i < map.height; i++) {
        my_putstr(map.content[i]);
        my_putchar('\n');
    }
}

void display_map(map_t *map)
{
    int max_x;
    int max_y;
    char *extend_msg = "Terminal window too small, please extend.";

    getmaxyx(stdscr, max_x, max_y);
    if (max_x < map->width || max_y < map->height) {
        mvprintw(max_x / 2, (max_y / 2) - my_strlen(extend_msg) / 2, "%s\n",
            extend_msg);
    } else {
        for (int i = 0; map->content[i] != NULL; i++) {
            mvprintw(i, 0, "%s", map->content[i]);
        }
    }
}
