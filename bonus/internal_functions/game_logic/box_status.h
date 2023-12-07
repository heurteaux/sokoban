/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** box_status.h
*/

#pragma once

#include <stdbool.h>
#include "../../data_structs/map.h"

bool is_on_line_stuck(map_t map, int y);
