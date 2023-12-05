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

bool is_win(char **map, position_t **o_pos_arr)
{
    for (int i = 0; o_pos_arr[i] != NULL; i++) {
        if (map[o_pos_arr[i]->y][o_pos_arr[i]->x] != 'X') {
            return false;
        }
    }
    return true;
}
