/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** internal_functions.h
*/

#pragma once

#include <stdbool.h>
#include "../includes/map.h"
#include "../includes/position.h"
#include "../includes/player_pos.h"

bool is_help_menu_requested(int argc, char **argv);

int help_menu(int argc, char **argv);

void start_sokoban(char **argv);

void setup_term(void);

player_pos_t get_player_pos(char **map);

void handle_controls(
    map_t *map, int key, position_t **O_pos_arr, char *map_path);

bool is_case_solid(char **map, int y, int x);

bool is_case_transparent(char **map, int y, int x);

bool is_case_box(char **map, int y, int x);

position_t **get_o_pos_arr(char **map);

bool is_win(char **map, position_t **o_pos_arr);

void print_map(map_t map);

void check_map_format(char *raw_map_content);

map_t init_map(char *map_path);

void check_game_lost(map_t map);
