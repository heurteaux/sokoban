/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <ncurses.h>
#include "../memory_managment.h"
#include "../map/init_map.h"
#include "../map/map_infos/o_pos_arr.h"
#include "../setup_ncurses.h"
#include "game_status.h"
#include "../map/displaying/display_map.h"
#include "../game_logic/input_handling.h"

void reset_game(map_t *map, char *map_path)
{
    free_map(*map);
    *map = init_map(map_path);
}

void start_game(char **argv)
{
    map_t map = init_map(argv[1]);
    position_t **o_pos_arr = get_o_pos_arr(map.content);
    int key = 0;

    setup_term();
    while (key != 27 && !is_win(map.content, o_pos_arr)) {
        check_game_lost(map);
        display_map(&map);
        key = getch();
        handle_controls(&map, key, o_pos_arr, argv[1]);
        clear();
        refresh();
    }
    display_map(&map);
    clear();
    refresh();
    endwin();
    free_map(map);
    free_pos_arr(o_pos_arr);
}
//ncurses does not free some memory for optimization / operating system reasons
