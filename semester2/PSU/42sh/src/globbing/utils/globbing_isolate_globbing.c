/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_loader
*/

#include "globbing.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>

/**
** @brief Use to isolate a globbing by removing every after the first '/'
** @param globbing The default globbing
** @param buffer The buffer where to write the new globbing
** @return The buffer given
**/
char *globbing_isolate(char *globbing, char *buffer)
{
    char *first_slash = strchr(globbing, '/');

    if (first_slash == NULL) {
        return strcpy(buffer, globbing);
    }
    buffer = strncpy(buffer, globbing, first_slash - globbing);
    buffer[first_slash - globbing] = 0;
    return buffer;
}
