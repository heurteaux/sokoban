/*
** EPITECH PROJECT, 2023
** Day03
** File description:
** displays a given int
*/

#include <unistd.h>
#include "my.h"

static const int ZERO = 48;

static int int_length(int a)
{
    int div_res = a;
    int counter = 0;

    if (a < 0) {
        while (div_res != 0) {
            div_res = (div_res / 10);
            counter++;
        }
    } else {
        while (div_res != 0) {
            div_res = div_res / 10;
            counter++;
        }
    }
    return counter;
}

__attribute__((unused)) int my_puterr_nbr(int nb_origin)
{
    int arg_length = int_length(nb_origin);
    long result_holder = 0;
    long nb = nb_origin;

    if (nb == 0) {
        write(2, &ZERO, 1);
        return 0;
    }
    if (nb > 0) {
        for_positive_err((int)nb, arg_length, result_holder);
    } else {
        write(2, "-", 1);
        for_negative_err(nb, arg_length, result_holder);
    }
    return 84;
}

/*void main(void) {
    my_put_nbr(2147483649);
}*/
