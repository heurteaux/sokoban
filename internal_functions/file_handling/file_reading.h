/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** file_reading.h
*/

#pragma once

char *get_file_content(const char *file_path);

char **get_map(char const *file_content, int height, int width);
