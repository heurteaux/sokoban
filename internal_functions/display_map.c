/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** display_map.c
*/

#include "../includes/my.h"
#include "../includes/map.h"

void print_map(map_t map)
{
    for (int i = 0; i < map.height; i++) {
        my_putstr(map.content[i]);
        my_putchar('\n');
    }
}
