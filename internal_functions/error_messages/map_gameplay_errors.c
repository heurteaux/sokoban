/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_gameplay_errors.c
*/

#include <stdlib.h>
#include "../../lib/my.h"

void err_box_base_nb_match(void)
{
    my_puterr("my_sokoban: The number of box and bases entities in the map do "
        "not match, the game would not be winnable\n");
    exit(84);
}

void err_get_player_pos(void)
{
    my_puterr("my_sokoban: Cannot get player pos\n");
    exit(84);
}
