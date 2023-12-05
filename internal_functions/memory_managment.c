/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** memory_management.c
*/

#include <malloc.h>
#include "../data_structs/position.h"
#include "../data_structs/map.h"

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

void free_pos_arr(position_t **pos_arr)
{
    for (int i = 0; pos_arr[i] != NULL; i++) {
        free(pos_arr[i]);
    }
    free(pos_arr);
}

void free_map(map_t map)
{
    for (int i = 0; i <= map.height; i++) {
        free(map.content[i]);
    }
    free(map.content);
}
