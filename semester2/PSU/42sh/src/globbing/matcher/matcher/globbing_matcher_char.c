/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_star
*/

#include "globbing.h"

#include <stdio.h>

bool globbing_matcher_char(char *globbing, char *string)
{
    if (globbing[0] != string[0]) {
        return false;
    }
    return globbing_matcher(globbing + 1, string + 1);
}
