/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** help_menu.c
*/

#include <malloc.h>
#include <stdbool.h>
#include "../lib/my.h"
#include "file_handling/file_reading.h"

const char *HELP_MENU_TEXT_FILE_PATH = "./config_files/help_menu_text";

int help_menu(int argc, char **argv)
{
    char *file_content;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'h') {
            file_content = get_file_content(HELP_MENU_TEXT_FILE_PATH);
            my_putstr(file_content);
            free(file_content);
        }
    }
    return 0;
}

bool is_help_menu_requested(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return true;
    return false;
}
