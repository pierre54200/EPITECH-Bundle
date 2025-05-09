/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_should_deep_search
*/

#include "globbing.h"

#include <string.h>

/**
** @brief Use to jump over the first '/' chain.
** @param path The current path
** @return A pointer to the first char after the '/' chain
**/
char *globbing_skip_dir(char *path)
{
    char *skipped = NULL;

    if (strchr(path, '/') == NULL) {
        return strchr(path, '\0');
    }
    skipped = strchr(path, '/') + 1;
    while (*skipped == '/') {
        skipped++;
    }
    return skipped;
}
