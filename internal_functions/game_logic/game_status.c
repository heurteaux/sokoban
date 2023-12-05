/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_status.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "../../data_structs/map.h"
#include "../../data_structs/position.h"
#include "box_status.h"
#include <ncurses.h>

bool is_win(char **map, position_t **o_pos_arr)
{
    for (int i = 0; o_pos_arr[i] != NULL; i++) {
        if (map[o_pos_arr[i]->y][o_pos_arr[i]->x] != 'X') {
            return false;
        }
    }
    return true;
}

void check_game_lost(map_t map)
{
    for (int y = 0; map.content[y] != NULL; y++) {
        if (!is_on_line_stuck(map, y))
            return;
    }
    clear();
    refresh();
    endwin();
    exit(1);
}
