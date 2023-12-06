/*
** EPITECH PROJECT, 2023
** my_puterr
** File description:
** myputerr
*/

#include <unistd.h>
#include "my.h"

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
