/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** O_pos_arr.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/position.h"

static void get_nb_pos_inner_cond(char **map, int y, int x, int *count)
{
    if (map[y][x] == 'O') {
        *count += 1;
    }
}

static int get_nb_pos(char **map)
{
    int count = 0;

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            get_nb_pos_inner_cond(map, y, x, &count);
        }
    }
    return count;
}

position_t **alloc_pos_arr(int size)
{
    position_t **pos_arr = malloc(sizeof(position_t *) * (size + 1));

    pos_arr[size] = NULL;
    return pos_arr;
}

static void get_o_pos_on_row(
    int *index, int y, char **map, position_t **o_pos_arr)
{
    position_t *temp_position;

    for (int x = 0; map[y][x] != '\0'; x++) {
        if (map[y][x] == 'O') {
            temp_position = malloc(sizeof(position_t) * 1);
            temp_position->y = y;
            temp_position->x = x;
            o_pos_arr[*index] = temp_position;
            *index += 1;
        }
    }
}

position_t **get_o_pos_arr(char **map)
{
    position_t **o_pos_arr = alloc_pos_arr(get_nb_pos(map));
    int index = 0;

    for (int y = 0; map[y] != NULL; y++) {
        get_o_pos_on_row(&index, y, map, o_pos_arr);
    }
    return o_pos_arr;
}
