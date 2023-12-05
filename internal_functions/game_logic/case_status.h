/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** case_status.h
*/

#pragma once
#include <stdbool.h>

bool is_case_solid(char **map, int y, int x);

bool is_case_transparent(char **map, int y, int x);

bool is_case_box(char **map, int y, int x);
