/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** input_handling.h
*/

#pragma once
#include "../../data_structs/map.h"
#include "../../data_structs/position.h"

void handle_controls(
    map_t *map, int key, position_t **O_pos_arr, char *map_path);
