/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_star
*/

#include "globbing.h"

#include <stdio.h>

bool globbing_matcher_single_wildcard(char *globbing, char *string)
{
    if (string[0] == '\0') {
        return false;
    }
    return globbing_matcher(globbing + 1, string + 1);
}
