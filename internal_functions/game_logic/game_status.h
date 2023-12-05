/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_status.h
*/

#pragma once
#include <stdbool.h>
#include "../../data_structs/map.h"
#include "../../data_structs/position.h"

bool is_win(char **map, position_t **o_pos_arr);

void check_game_lost(map_t map);
