/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task08
*/

__attribute__((unused)) char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
        }
    }
    return str;
}
