/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** memory_managment.c
*/

#include <malloc.h>
#include "../data_structs/position.h"

char **alloc_2d_arr(int height, int width)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    int i = 0;

    for (; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 2));
        for (int n = 0; n < (width + 2); n++) {
            map[i][n] = 0;
        }
    }
    map[i] = NULL;
    return map;
}

position_t **alloc_pos_arr(int size)
{
    position_t **pos_arr = malloc(sizeof(position_t *) * (size + 1));

    pos_arr[size] = NULL;
    return pos_arr;
}
