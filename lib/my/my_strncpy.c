/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** task02
*/

#include <unistd.h>
char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        if (dest[i + 1] == '\0') {
            dest[i] = src[i];
            dest[i + 1] = '\0';
            return dest;
        }
        if (src[i] == '\0') {
            dest[i] = '\0';
            break;
        }
        dest[i] = src[i];
    }
    return dest;
}

/*void read_str(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        write(1, &str[i], 1);
    }
    write(1, &RTRN, 1);
}
    //read_str(str_src);
    }*/
