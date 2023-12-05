/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_format.c
*/

#include <stdlib.h>

static void check_map_chars(const char *raw_map_content)
{
    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        switch (raw_map_content[i]) {
            case ' ':
                break;
            case '#':
                break;
            case 'O':
                break;
            case 'P':
                break;
            case 'X':
                break;
            case '\n':
                break;
            default:
                exit(84);
        }
    }
}

static void check_player_number(const char *raw_map_content)
{
    int player_nb = 0;

    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == 'P')
            player_nb++;
        if (player_nb > 1)
            exit(84);
    }
}

static int check_base_number(const char *raw_map_content)
{
    int base_nb = 0;

    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == 'O')
            base_nb++;
    }
    if (base_nb == 0)
        exit(84);
    return base_nb;
}

static int check_box_number(const char *raw_map_content)
{
    int box_nb = 0;

    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == 'X') {
            box_nb++;
        }
    }
    if (box_nb == 0)
        exit(84);
    return box_nb;
}

static void check_box_and_base_number(char *raw_map_content)
{
    int base_nb = check_base_number(raw_map_content);
    int box_nb = check_box_number(raw_map_content);

    if (base_nb != box_nb) {
        exit(84);
    }
}

void check_map_format(char *raw_map_content)
{
    check_map_chars(raw_map_content);
    check_player_number(raw_map_content);
    check_box_and_base_number(raw_map_content);
}
