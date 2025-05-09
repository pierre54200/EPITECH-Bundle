/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_star
*/

#include "globbing.h"

bool globbing_matcher_any_wildcard(char *globbing, char *string)
{
    while (string[0] != '\0') {
        if (globbing_matcher(globbing + 1, string)) {
            return true;
        }
        string++;
    }
    return globbing[1] == '\0';
}
