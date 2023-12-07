/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game.h
*/

#pragma once
#include "../../data_structs/map.h"

void reset_game(map_t *map, char *map_path);

void start_game(char **argv);
