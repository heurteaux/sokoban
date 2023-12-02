/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** internal_functions.h
*/

#pragma once

#include <stdbool.h>
#include "../includes/player_pos.h"
#include "../includes/position.h"

bool is_help_menu_requested(int argc, char **argv);

int help_menu(int argc, char **argv);

void start_sokoban(char **argv);

void setup_term(void);

player_pos_t get_player_pos(char **map);

void handle_controls(char **map, int key, position_t **O_pos_arr);

bool is_case_solid(char **map, int y, int x);

bool is_case_transparent(char **map, int y, int x);

bool is_case_box(char **map, int y, int x);

position_t **get_o_pos_arr(char **map);
