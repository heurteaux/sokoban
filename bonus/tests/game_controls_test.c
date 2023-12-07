/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** game_controls_test.c
*/

#include <criterion/criterion.h>
#include "../data_structs/map.h"
#include "../internal_functions/map/init_map.h"
#include "../internal_functions/game_logic/input_handling.h"
#include "../internal_functions/map/map_infos/o_pos_arr.h"
#include <ncurses.h>

Test(sokoban, base_player_up)
{
    map_t test_map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_UP, o_pos_arr, "tests/test_map");
    cr_assert_eq(test_map.content[2][5], ' ');
    cr_assert_eq(test_map.content[1][5], 'P');
}

Test(sokoban, base_player_down)
{
    map_t test_map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_DOWN, o_pos_arr, "tests/test_map");
    cr_assert_eq(test_map.content[2][5], ' ');
    cr_assert_eq(test_map.content[3][5], 'P');
}

Test(sokoban, base_player_right)
{
    map_t test_map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_RIGHT, o_pos_arr, "tests/test_map");
    cr_assert_eq(test_map.content[2][5], ' ');
    cr_assert_eq(test_map.content[2][6], 'P');
}

Test(sokoban, base_player_left)
{
    map_t test_map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_LEFT, o_pos_arr, "tests/test_map");
    cr_assert_eq(test_map.content[2][5], ' ');
    cr_assert_eq(test_map.content[2][4], 'P');
}

Test(sokoban, base_o_case_leave)
{
    map_t test_map = init_map("tests/test_map");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_UP, o_pos_arr, "tests/test_map");
    handle_controls(&test_map, KEY_DOWN, o_pos_arr, "tests/test_map");
    cr_assert_eq(test_map.content[2][5], 'P');
    cr_assert_eq(test_map.content[1][5], 'O');
}

Test(sokoban, solid_player_up)
{
    map_t test_map = init_map("tests/map_test_solid");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_UP, o_pos_arr, "tests/map_test_solid");
    cr_assert_eq(test_map.content[1][1], 'P');
    cr_assert_eq(test_map.content[0][1], '#');
}

Test(sokoban, solid_player_down)
{
    map_t test_map = init_map("tests/map_test_solid");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_DOWN, o_pos_arr, "tests/map_test_solid");
    cr_assert_eq(test_map.content[1][1], 'P');
    cr_assert_eq(test_map.content[2][1], '#');
}

Test(sokoban, solid_player_right)
{
    map_t test_map = init_map("tests/map_test_solid");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_RIGHT, o_pos_arr, "tests/map_test_solid");
    cr_assert_eq(test_map.content[1][1], 'P');
    cr_assert_eq(test_map.content[1][2], '#');
}

Test(sokoban, solid_player_left)
{
    map_t test_map = init_map("tests/map_test_solid");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_LEFT, o_pos_arr, "tests/map_test_solid");
    cr_assert_eq(test_map.content[1][1], 'P');
    cr_assert_eq(test_map.content[1][0], '#');
}

Test(sokoban, base_box_move_up)
{
    map_t test_map = init_map("tests/map_test_box_move");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_UP, o_pos_arr, "tests/map_test_box_move");
    cr_assert_eq(test_map.content[3][3], ' ');
    cr_assert_eq(test_map.content[2][3], 'P');
    cr_assert_eq(test_map.content[1][3], 'X');
}

Test(sokoban, base_box_move_down)
{
    map_t test_map = init_map("tests/map_test_box_move");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_DOWN, o_pos_arr, "tests/map_test_box_move");
    cr_assert_eq(test_map.content[3][3], ' ');
    cr_assert_eq(test_map.content[4][3], 'P');
    cr_assert_eq(test_map.content[5][3], 'X');
}

Test(sokoban, base_box_move_right)
{
    map_t test_map = init_map("tests/map_test_box_move");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_RIGHT, o_pos_arr, "tests/map_test_box_move");
    cr_assert_eq(test_map.content[3][3], ' ');
    cr_assert_eq(test_map.content[3][4], 'P');
    cr_assert_eq(test_map.content[3][5], 'X');
}

Test(sokoban, base_box_move_left)
{
    map_t test_map = init_map("tests/map_test_box_move");
    position_t **o_pos_arr = get_o_pos_arr(test_map.content);

    handle_controls(&test_map, KEY_LEFT, o_pos_arr, "tests/map_test_box_move");
    cr_assert_eq(test_map.content[3][3], ' ');
    cr_assert_eq(test_map.content[3][2], 'P');
    cr_assert_eq(test_map.content[3][1], 'X');
}
