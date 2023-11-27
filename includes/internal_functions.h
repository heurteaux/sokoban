/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** internal_functions.h
*/

#pragma once

#include <stdbool.h>
#include "../includes/player_pos.h"

bool is_help_menu_requested(int argc, char **argv);

int help_menu(int argc, char **argv);

void start_sokoban(char **argv);

void setup_term(void);

player_pos_t get_player_pos(char **map);

void handle_controls(char **map, int key, bool *O_undr_playr);

bool is_case_solid(char **map, int y, int x);

bool is_case_transparent(char **map, int y, int x);
