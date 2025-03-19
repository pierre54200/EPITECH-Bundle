/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** alpha
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (is_a_char(str[i]) == 1)
            return 0;
    }
    return 1;
}
