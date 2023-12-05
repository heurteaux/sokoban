/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** box_status.c
*/

#include <stdbool.h>
#include "case_status.h"
#include "../../data_structs/map.h"

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
