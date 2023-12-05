/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/my.h"
#include "../includes/file_reading.h"
#include "../includes/internal_functions.h"
#include "../includes/map_infos.h"

static char **alloc_2d_arr(int height, int width)
{
    char **map = malloc(sizeof(char *) * (height + 1));
    int i = 0;

    for (; i < height; i++) {
        map[i] = malloc(sizeof(char) * (width + 2));
        for (int n = 0; n < (width + 2); n++) {
            map[i][n] = 0;
        }
    }
    map[i] = NULL;
    return map;
}

char **get_map(char const *file_content, int height, int width)
{
    char **map = alloc_2d_arr(height, width);
    int row_index = 0;
    int row = 0;

    for (int i = 0; file_content[i] != '\0'; i++) {
        if (file_content[i] == '\n') {
            row++;
            row_index = 0;
            continue;
        }
        map[row][row_index] = file_content[i];
        row_index++;
    }
    return map;
}

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

void display_map(map_t *map)
{
    int max_x;
    int max_y;
    char *extend_msg = "Terminal window too small, please extend.";

    getmaxyx(stdscr, max_x, max_y);
    if (max_x < map->width || max_y < map->height) {
        mvprintw(max_x / 2, (max_y / 2) - my_strlen(extend_msg) / 2, "%s\n",
            extend_msg);
    } else {
        for (int i = 0; map->content[i] != NULL; i++) {
            mvprintw(i, 0, "%s", map->content[i]);
        }
    }
}

void start_sokoban(char **argv)
{
    map_t map = init_map(argv[1]);
    position_t **o_pos_arr = get_o_pos_arr(map.content);
    int key = 0;

    setup_term();
    while (key != 27 && !is_win(map.content, o_pos_arr)) {
        display_map(&map);
        key = getch();
        handle_controls(&map, key, o_pos_arr, argv[1]);
        check_game_lost(map);
        clear();
        refresh();
    }
    endwin();
}
