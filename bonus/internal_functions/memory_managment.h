/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** memory_management.h
*/

#pragma once
#include "../data_structs/position.h"
#include "../data_structs/map.h"

char **alloc_2d_arr(int height, int width);

position_t **alloc_pos_arr(int size);

void free_pos_arr(position_t **pos_arr);

void free_map(map_t map);
