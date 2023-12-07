/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** player_pos.h
*/

#pragma once
#include "../../data_structs/map.h"

typedef struct player_pos_s {
    int y;
    int x;
} player_pos_t;

player_pos_t get_player_pos(map_t *map);
