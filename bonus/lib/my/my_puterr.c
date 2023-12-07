/*
** EPITECH PROJECT, 2023
** my_puterr
** File description:
** myputerr
*/

#include <unistd.h>
#include "my.h"

__attribute__((unused)) void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
