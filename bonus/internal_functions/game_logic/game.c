/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <ncurses.h>
#include <SFML/Audio.h>
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

sfMusic *start_music()
{
    sfMusic *main_theme = sfMusic_createFromFile("./config_files/doom_music.ogg");
    sfMusic_setLoop(main_theme, sfTrue);
    sfMusic_play(main_theme);
    return main_theme;
}

void start_game(char **argv)
{
    map_t map = init_map(argv[1]);
    position_t **o_pos_arr = get_o_pos_arr(map.content);
    int key = 0;
    sfMusic *music = start_music();

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
    refresh();
    endwin();
    sfMusic_stop(music);
    free_map(map);
    free_pos_arr(o_pos_arr);
}
//ncurses does not free some memory for optimization / operating system reasons
