/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** input_handling.c
*/

#include <ncurses.h>
#include "../../data_structs/position.h"
#include "../../data_structs/map.h"
#include "player_pos.h"
#include "case_status.h"
#include "game.h"

static bool is_base_on_pos(int y, int x, position_t **O_pos_arr)
{
    for (int i = 0; O_pos_arr[i] != NULL; i++) {
        if (O_pos_arr[i]->y == y && O_pos_arr[i]->x == x)
            return true;
    }
    return false;
}

static bool is_box_move_y(map_t *map, int distance)
{
    player_pos_t player_pos = get_player_pos(map);

    return (is_case_box(map->content, player_pos.y + distance, player_pos.x)
        && !is_case_solid(
            map->content, player_pos.y + (distance + distance), player_pos.x)
        && !is_case_solid(map->content, player_pos.y + distance, player_pos.x)
        && !is_case_box(map->content,
            player_pos.y + (distance + (distance < 0 ? -1 : 1)),
            player_pos.x));
}

static bool is_box_move_x(map_t *map, int distance)
{
    player_pos_t player_pos = get_player_pos(map);

    return (is_case_box(map->content, player_pos.y, player_pos.x + distance)
        && !is_case_solid(
            map->content, player_pos.y, player_pos.x + (distance + distance))
        && !is_case_solid(map->content, player_pos.y, player_pos.x + distance)
        && !is_case_box(map->content, player_pos.y,
            player_pos.x + (distance + (distance < 0 ? -1 : 1))));
}

static void mv_player_y(map_t *map, int distance, position_t **O_pos_arr)
{
    player_pos_t player_pos = get_player_pos(map);
    int offset;

    if (is_box_move_y(map, distance)) {
        offset = (distance < 0 ? -1 : 1);
        map->content[player_pos.y][player_pos.x] = ' ';
        map->content[player_pos.y + distance][player_pos.x] = 'P';
        map->content[player_pos.y + (distance + offset)][player_pos.x] = 'X';
    }
    if (!is_case_solid(map->content, player_pos.y + distance, player_pos.x)
        && !is_case_box(map->content, player_pos.y + distance, player_pos.x)
        && player_pos.y + distance < map->height && player_pos.y >= 0) {
        map->content[player_pos.y][player_pos.x] = ' ';
        if (is_base_on_pos(player_pos.y, player_pos.x, O_pos_arr))
            map->content[player_pos.y][player_pos.x] = 'O';
        map->content[player_pos.y + distance][player_pos.x] = 'P';
        return;
    }
}

static void mv_player_x(map_t *map, int distance, position_t **O_pos_arr)
{
    player_pos_t player_pos = get_player_pos(map);
    int offset;

    if (is_box_move_x(map, distance)) {
        offset = (distance < 0 ? -1 : 1);
        map->content[player_pos.y][player_pos.x] = ' ';
        map->content[player_pos.y][player_pos.x + distance] = 'P';
        map->content[player_pos.y][player_pos.x + (distance + offset)] = 'X';
    }
    if (!is_case_solid(map->content, player_pos.y, player_pos.x + distance)
        && !is_case_box(map->content, player_pos.y, player_pos.x + distance)
        && player_pos.x + distance < map->width && player_pos.x >= 0) {
        map->content[player_pos.y][player_pos.x] = ' ';
        if (is_base_on_pos(player_pos.y, player_pos.x, O_pos_arr))
            map->content[player_pos.y][player_pos.x] = 'O';
        map->content[player_pos.y][player_pos.x + distance] = 'P';
    }
}

void handle_controls(
    map_t *map, int key, position_t **O_pos_arr, char *map_path)
{
    switch (key) {
        case KEY_UP:
            mv_player_y(map, -1, O_pos_arr);
            break;
        case KEY_DOWN:
            mv_player_y(map, 1, O_pos_arr);
            break;
        case KEY_RIGHT:
            mv_player_x(map, 1, O_pos_arr);
            break;
        case KEY_LEFT:
            mv_player_x(map, -1, O_pos_arr);
            break;
        case ' ':
            reset_game(map, map_path);
        default:
            break;
    }
}
