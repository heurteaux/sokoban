/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../includes/map.h"
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

    map.width = get_map_width(file_content);
    map.height = get_map_height(file_content);
    map.content = get_map(file_content, map.height, map.width);
    return map;
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        mvprintw(i, 0, "%s", map[i]);
    }
}

void start_sokoban(char **argv)
{
    map_t map = init_map(argv[1]);
    int key = 0;
    bool O_undr_playr = false;

    setup_term();
    while (key != 27) {
        display_map(map.content);
        refresh();
        key = getch();
        handle_controls(map.content, key, &O_undr_playr);
        clear();
    }
    endwin();
}
