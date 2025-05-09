/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_const
*/

#include "globbing.h"

#include <string.h>

/**
** @brief Use to find a globbing matcher for a given globbing
** @param globbing The given globbing
** @return The found globbing matcher or a matcher filled by 0
**/
globbing_matcher_t globbing_find_matcher(char *globbing)
{
    globbing_matcher_t found = { 0 };
    globbing_matcher_t current = { 0 };

    for (size_t i = 0; i < globbing_matcher_count; i++) {
        current = globbing_matchers[i];
        if (found.key != 0 && strlen(found.key) > strlen(current.key))
            continue;
        if (strncmp(globbing, current.key, strlen(current.key)) == 0) {
            found = current;
        }
    }
    return found;
}
