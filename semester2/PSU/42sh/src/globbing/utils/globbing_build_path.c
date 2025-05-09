/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_loader
*/

#include "globbing.h"
#include "string_utils.h"

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <alloca.h>

/**
** @brief Use to fill a buffer with the next dir.
** @param dir_from The current directory where to search.
** @param target_sub_dir The Target sub dir
** @param buffer The buffer where the new path will be wrote
** @return The buffer
**/
char *globbing_build_path(char *dir_from, char *target, char *buffer)
{
    if (strcmp(dir_from, ".") == 0) {
        return strcpy(buffer, target);
    }
    return strcat(strcat(strcpy(buffer, dir_from), "/"), target);
}
