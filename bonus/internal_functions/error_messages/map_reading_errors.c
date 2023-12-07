/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_reading_errors.c
*/

#include "../../lib/my.h"
#include <stdlib.h>

void err_invalid_map_character(void)
{
    my_puterr("my_sokoban: The map contains an invalid character, "
        "only valid characters are '#' 'X' 'P' 'O' '\\n' and SPACE.\n");
    exit(84);
}

void err_cannot_open_file(void)
{
    my_puterr("my_sokoban: Cannot open file\n");
    exit(84);
}

void err_invalid_player_number(void)
{
    my_puterr("my_sokoban: The map contains an "
        "invalid number of player entities\n");
    exit(84);
}

void err_invalid_base_number(void)
{
    my_puterr("my_sokoban: The map contains an "
        "invalid number of base entities\n");
    exit(84);
}

void err_invalid_box_number(void)
{
    my_puterr("my_sokoban: The map contains an "
        "invalid number of box entities\n");
    exit(84);
}
