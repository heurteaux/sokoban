/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** player_pos.h
*/

#pragma once

typedef struct player_pos_s {
    int y;
    int x;
} player_pos_t;

player_pos_t get_player_pos(char **map);
