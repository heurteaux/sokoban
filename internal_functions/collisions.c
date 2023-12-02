/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** collisions.c
*/

#include <stdbool.h>

bool is_case_solid(char **map, int y, int x)
{
    return map[y][x] == '#';
}

bool is_case_transparent(char **map, int y, int x)
{
    return map[y][x] == 'O';
}

bool is_case_box(char **map, int y, int x)
{
    return map[y][x] == 'X';
}
