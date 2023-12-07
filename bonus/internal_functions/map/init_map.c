/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** init_map.c
*/

#include "../../data_structs/map.h"
#include "map_infos/get_map_infos.h"
#include "map_validity/map_format.h"
#include "../file_handling/file_reading.h"

map_t init_map(char *map_path)
{
    char *file_content = get_file_content(map_path);
    map_t map;

    check_map_format(file_content);
    map.width = get_map_width(file_content);
    map.height = get_map_height(file_content);
    map.content = get_map(file_content, map.height, map.width);
    return map;
}
