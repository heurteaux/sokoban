/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_status.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/position.h"
#include "../../includes/map.h"
#include "../../includes/internal_functions.h"
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

static bool is_stuck_top_left(char **map, int y, int x)
{
    return is_case_solid(map, y - 1, x) && is_case_solid(map, y, x - 1);
}

static bool is_stuck_top_right(char **map, int y, int x)
{
    return is_case_solid(map, y - 1, x) && is_case_solid(map, y, x + 1);
}

static bool is_stuck_bottom_left(char **map, int y, int x)
{
    return is_case_solid(map, y, x - 1) && is_case_solid(map, y + 1, x);
}

static bool is_stuck_bottom_right(char **map, int y, int x)
{
    return is_case_solid(map, y, x + 1) && is_case_solid(map, y + 1, x);
}

static bool is_stuck(char **map, int y, int x)
{
    if (is_stuck_top_left(map, y, x)) {
        return true;
    }
    if (is_stuck_top_right(map, y, x)) {
        return true;
    }
    if (is_stuck_bottom_left(map, y, x)) {
        return true;
    }
    if (is_stuck_bottom_right(map, y, x)) {
        return true;
    }
    return false;
}

bool is_on_line_stuck(map_t map, int y)
{
    for (int x = 0; map.content[y][x] != '\0'; x++) {
        if (map.content[y][x] == 'X' && !is_stuck(map.content, y, x))
            return false;
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
