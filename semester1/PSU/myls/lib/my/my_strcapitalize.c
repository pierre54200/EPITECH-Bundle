/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** put a uppercase at the begging
*/
#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && (is_a_char(str[i - 1]) == 1)
            && (str[i - 1] < '0' || str[i - 1] > '9'))
            str[i] = str[i] - 32;
        if (str[i] >= 'A' && str[i] <= 'Z' && (is_a_char(str[i - 1]) == 0)
            && (str[i - 1] >= '0' || str[i - 1] <= '9'))
            str[i] = str[i] + 32;
    }
    return str;
}
