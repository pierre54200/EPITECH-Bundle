/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_should_deep_search
*/

#include "globbing.h"

#include <string.h>

/**
** @brief Use to see if you should deep search a globbing by checking
**   if the next '/' chain end by a '\0'
** @param globbing The globbing
** @return True if should deep search
**/
bool globbing_should_deep_search(char *globbing)
{
    char *ptr = strchr(globbing, '/');

    if (ptr == NULL) {
        return false;
    }
    for (; (*ptr) != '\0' && (*ptr) == '/'; ptr++);
    return (*ptr) != '\0';
}
