/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** map_tests.c
*/

#include <criterion/criterion.h>
#include "../internal_functions/map/init_map.h"
#include "../data_structs/position.h"
#include "../internal_functions/map/map_infos/o_pos_arr.h"
#include "../internal_functions/game_logic/player_pos.h"
#include <stdio.h>

Test(sokoban, check_map_from_file)
{
    map_t test_map = init_map("tests/test_map");
    char *map_content[] = {"#############",
                          "#    O      #",
                          "#    P      #",
                          "#       #####",
                          "#      #    #",
                          "#     #   O #",
                          "#            ######",
                          "#                 #",
                          "#     X           #",
                          "#     X          #",
                          "#O     X        #",
                          "################"};

    cr_assert_eq(test_map.width, 19);
    cr_assert_eq(test_map.height, 12);
    for (int i = 0; test_map.content[i] != NULL; i++) {
        cr_assert_str_eq(test_map.content[i], map_content[i]);
    }
}

Test(sokoban, map_two_players, .exit_code = 84)
{
    init_map("tests/map_test_two_players");
    cr_assert_fail("init_map() should have failed.");
}

Test(sokoban, map_no_players, .exit_code = 84)
{
    init_map("tests/map_test_no_players");
    cr_assert_fail("init_map() should have failed.");
}

Test(sokoban, map_no_boxes, .exit_code = 84)
{
    init_map("tests/map_test_no_box");
    cr_assert_fail("init_map() should have failed.");
}

Test(sokoban, map_no_base, .exit_code = 84)
{
    init_map("tests/map_test_no_base");
    cr_assert_fail("init_map() should have failed.");
}

Test(sokoban, map_invalid_char, .exit_code = 84)
{
    init_map("tests/map_test_invalid_char");
    cr_assert_fail("init_map() should have failed");
}

Test(sokoban, map_box_base_match, .exit_code = 84)
{
    init_map("tests/map_test_box_base_match");
    cr_assert_fail("init_map() should have failed");
}

Test(sokoban, map_box_base_match_2, .exit_code = 84)
{
    init_map("tests/map_test_box_base_match_2");
    cr_assert_fail("init_map() should have failed");
}

Test(sokoban, map_invalid_path, .exit_code = 84)
{
    init_map("tests/invalid_path");
    cr_assert_fail("init_map() should have failed");
}

Test(sokoban, map_o_pos_arr_validity)
{
    map_t map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(map.content);

    cr_assert_eq(o_pos_arr[0]->y, 1);
    cr_assert_eq(o_pos_arr[0]->x, 5);
    cr_assert_eq(o_pos_arr[1]->y, 5);
    cr_assert_eq(o_pos_arr[1]->x, 10);
    cr_assert_eq(o_pos_arr[2]->y, 10);
    cr_assert_eq(o_pos_arr[2]->x, 1);
}

Test(sokoban, get_player_pos)
{
    map_t map = init_map("tests/test_map");
    player_pos_t player_pos = get_player_pos(&map);

    cr_assert_eq(player_pos.y, 2);
    cr_assert_eq(player_pos.x, 5);
}

Test(sokoban, get_player_pos_err, .exit_code = 84)
{
    map_t map = init_map("tests/test_map");
    map.content = (char *[15]){"#############\n",
                   "#    O      #\n",
                   "#           #\n",
                   "#       #####\n",
                   "#      #    #\n",
                   "#     #   O #\n",
                   "#            ######\n",
                   "#                 #\n",
                   "#     X           #\n",
                   "#     X          #\n",
                   "#O     X        #\n",
                   "################\n"};
    player_pos_t player_pos = get_player_pos(&map);
    cr_assert_fail("Must fail");
}
