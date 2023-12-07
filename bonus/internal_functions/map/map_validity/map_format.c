/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_format.c
*/

#include "../../error_messages/map_reading_errors.h"
#include "../../error_messages/map_gameplay_errors.h"

static void check_map_chars(const char *raw_map_content)
{
    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == ' ')
            continue;
        if (raw_map_content[i] == '#')
            continue;
        if (raw_map_content[i] == 'O')
            continue;
        if (raw_map_content[i] == 'P')
            continue;
        if (raw_map_content[i] == 'X')
            continue;
        if (raw_map_content[i] == '\n')
            continue;
        err_invalid_map_character();
    }
}

static void check_player_number(const char *raw_map_content)
{
    int player_nb = 0;

    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == 'P')
            player_nb++;
        if (player_nb > 1)
            err_invalid_player_number();
    }
    if (player_nb < 1)
        err_invalid_player_number();
}

static int check_base_number(const char *raw_map_content)
{
    int base_nb = 0;

    for (int i = 0; raw_map_content[i] != '\0'; i++) {
        if (raw_map_content[i] == 'O')
            base_nb++;
    }
    if (base_nb == 0)
        err_invalid_base_number();
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
        err_invalid_box_number();
    return box_nb;
}

static void check_box_and_base_number(char *raw_map_content)
{
    int base_nb = check_base_number(raw_map_content);
    int box_nb = check_box_number(raw_map_content);

    if (base_nb != box_nb) {
        err_box_base_nb_match();
    }
}

void check_map_format(char *raw_map_content)
{
    check_map_chars(raw_map_content);
    check_player_number(raw_map_content);
    check_box_and_base_number(raw_map_content);
}
