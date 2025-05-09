/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher
*/

#include "globbing.h"

/**
** @brief Use to check if a string match a globbing
** @param globbing The given globbing
** @param string The string to check if it's match
** @return True if the globbing match the string else False.
**/
bool globbing_matcher(char *globbing, char *string)
{
    globbing_matcher_t matcher = globbing_find_matcher(globbing);

    if (globbing[0] == '\0' && string[0] == '\0') {
        return true;
    }
    return matcher.matching(globbing, string);
}
