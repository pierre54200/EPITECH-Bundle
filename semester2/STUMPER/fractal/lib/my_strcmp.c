/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** compare two strings
*/

#include "../proto.h"

int my_strcmp(const char *s1, const char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}
