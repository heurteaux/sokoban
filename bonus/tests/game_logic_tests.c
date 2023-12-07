/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_logic_tests.c
*/

#include <criterion/criterion.h>
#include "../internal_functions/game_logic/game_status.h"
#include "../internal_functions/map/map_infos/o_pos_arr.h"
#include "../internal_functions/map/init_map.h"
#include "../internal_functions/game_logic/case_status.h"
#include "../internal_functions/game_logic/game.h"
#include <stdio.h>

Test(sokoban, is_win_true)
{
    map_t test_map = init_map("tests/test_map");
    char *win_map[] = {"#############\n",
                      "#    X      #\n",
                      "#    P      #\n",
                      "#       #####\n",
                      "#      #    #\n",
                      "#     #   X #\n",
                      "#            ######\n",
                      "#                 #\n",
                      "#                 #\n",
                      "#                #\n",
                      "#X              #\n",
                      "################\n"};
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    cr_assert(is_win(win_map, o_pos_arr), "Expression must be true");
}

Test(sokoban, is_win_false)
{
    map_t test_map = init_map("tests/test_map");
    char *win_map[] = {"#############\n",
        "#    O      #\n",
        "#    PX     #\n",
        "#       #####\n",
        "#      #    #\n",
        "#     #   X #\n",
        "#            ######\n",
        "#                 #\n",
        "#                 #\n",
        "#                #\n",
        "#X              #\n",
        "################\n"};
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    cr_assert(!is_win(win_map, o_pos_arr), "Expression must be true");
}

Test(sokoban, is_loose_true, .exit_code = 1)
{
    map_t test_map = init_map("tests/map_test_loose");

    check_game_lost(test_map);
    cr_assert_fail("Must fail");
}

Test(sokoban, is_loose_false)
{
    map_t test_map = init_map("tests/map_test_not_loose");

    check_game_lost(test_map);
}

Test(sokoban, is_case_solid_true)
{
    char *map[] = {"#############\n",
                    "#X   O     X#\n",
                    "#     P     #\n"
                    "#       #####\n",
                    "#      #    #\n",
                    "#     #   O #\n",
                    "#            ######\n",
                    "#                 #\n",
                    "#         O       #\n",
                    "#                #\n",
                    "#X      O      X#\n",
                    "################\n"};

    cr_assert(is_case_solid(map, 0, 0));
}

Test(sokoban, is_case_solid_false)
{
    char *map[] = {"#############\n",
        "#X   O     X#\n",
        "#     P     #\n"
        "#       #####\n",
        "#      #    #\n",
        "#     #   O #\n",
        "#            ######\n",
        "#                 #\n",
        "#         O       #\n",
        "#                #\n",
        "#X      O      X#\n",
        "################\n"};

    cr_assert(!is_case_solid(map, 1, 1));
}

Test(sokoban, is_case_box_true)
{
    char *map[] = {"#############\n",
        "#X   O     X#\n",
        "#     P     #\n"
        "#       #####\n",
        "#      #    #\n",
        "#     #   O #\n",
        "#            ######\n",
        "#                 #\n",
        "#         O       #\n",
        "#                #\n",
        "#X      O      X#\n",
        "################\n"};

    cr_assert(is_case_box(map, 1, 1));
}

Test(sokoban, is_case_box_false)
{
    char *map[] = {"#############\n",
        "#X   O     X#\n",
        "#     P     #\n"
        "#       #####\n",
        "#      #    #\n",
        "#     #   O #\n",
        "#            ######\n",
        "#                 #\n",
        "#         O       #\n",
        "#                #\n",
        "#X      O      X#\n",
        "################\n"};

    cr_assert(!is_case_box(map, 0, 0));
}

Test(sokoban, is_case_transparent_true)
{
    char *map[] = {"#############\n",
        "#X   O     X#\n",
        "#     P     #\n"
        "#       #####\n",
        "#      #    #\n",
        "#     #   O #\n",
        "#            ######\n",
        "#                 #\n",
        "#         O       #\n",
        "#                #\n",
        "#X      O      X#\n",
        "################\n"};

    cr_assert(is_case_transparent(map, 1, 5));
}

Test(sokoban, is_case_transparent_false)
{
    char *map[] = {"#############\n",
        "#X   O     X#\n",
        "#     P     #\n"
        "#       #####\n",
        "#      #    #\n",
        "#     #   O #\n",
        "#            ######\n",
        "#                 #\n",
        "#         O       #\n",
        "#                #\n",
        "#X      O      X#\n",
        "################\n"};

    cr_assert(!is_case_transparent(map, 0, 0));
}

Test(sokoban, reset_map)
{
    map_t test_map = init_map("tests/map_test_loose");
    map_t base_map = init_map("tests/test_map");

    reset_game(&test_map, "tests/test_map");
    for (int i = 0; test_map.content[i] != NULL; i++) {
        cr_assert_str_eq(test_map.content[i], base_map.content[i]);
    }
}
