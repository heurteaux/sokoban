/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** memory_managment.h
*/

#pragma once
#include "../data_structs/position.h"

char **alloc_2d_arr(int height, int width);

position_t **alloc_pos_arr(int size);
