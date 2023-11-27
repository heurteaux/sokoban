/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** input_handling.c
*/

#include <ncurses.h>
#include "../includes/internal_functions.h"
#include "../includes/player_pos.h"

void mv_player_y(char **map, int distance, bool *O_undr_playr)
{
    player_pos_t player_pos = get_player_pos(map);

    if (!is_case_solid(map, player_pos.y + distance, player_pos.x)) {
        if (is_case_transparent(map, player_pos.y + distance, player_pos.x))
            *O_undr_playr = true;
        map[player_pos.y][player_pos.x] = ' ';
        printf("%b\n", *O_undr_playr);
        if (!is_case_transparent(map, player_pos.y + distance, player_pos.x)
            && *O_undr_playr) {
            map[player_pos.y][player_pos.x] = 'O';
            *O_undr_playr = false;
        }
        map[player_pos.y + distance][player_pos.x] = 'P';
    }
}

void mv_player_x(char **map, int distance, bool *O_undr_playr)
{
    player_pos_t player_pos = get_player_pos(map);

    if (!is_case_solid(map, player_pos.y, player_pos.x + distance)) {
        if (is_case_transparent(map, player_pos.y, player_pos.x + distance))
            *O_undr_playr = true;
        map[player_pos.y][player_pos.x] = ' ';
        printf("%b\n", *O_undr_playr);
        if (!is_case_transparent(map, player_pos.y, player_pos.x + distance)
            && *O_undr_playr) {
            map[player_pos.y][player_pos.x] = 'O';
            *O_undr_playr = false;
        }
        map[player_pos.y][player_pos.x + distance] = 'P';
    }
}

void handle_controls(char **map, int key, bool *O_undr_playr)
{
    switch (key) {
        case KEY_UP:
            mv_player_y(map, -1, O_undr_playr);
            break;
        case KEY_DOWN:
            mv_player_y(map, 1, O_undr_playr);
            break;
        case KEY_RIGHT:
            mv_player_x(map, 1, O_undr_playr);
            break;
        case KEY_LEFT:
            mv_player_x(map, -1, O_undr_playr);
            break;
        default:
            break;
    }
}
