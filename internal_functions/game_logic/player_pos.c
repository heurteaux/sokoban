/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** player_pos.c
*/

#include "player_pos.h"
#include "../error_messages/map_gameplay_errors.h"
#include <stddef.h>


static int is_player_line(char **map, int y)
{
    for (int x = 0; map[y][x] != '\0'; x++) {
        if (map[y][x] == 'P')
            return x;
    }
    return (-1);
}

player_pos_t get_player_pos(char **map)
{
    player_pos_t disappear_warning = {};

    for (int y = 0; map[y] != NULL; y++) {
        if (is_player_line(map, y) != (-1))
            return (player_pos_t){y, is_player_line(map, y)};
    }
    err_get_player_pos();
    return disappear_warning;
}
