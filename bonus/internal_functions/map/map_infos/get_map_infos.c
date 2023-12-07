/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get_map_infos.c
*/

int get_map_width(char const *map)
{
    int width = 0;
    int current_line_len = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            current_line_len = 0;
        if (current_line_len > width)
            width = current_line_len;
        current_line_len++;
    }
    return width;
}

int get_map_height(char const *map)
{
    int height = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            height++;
    }
    return height;
}
