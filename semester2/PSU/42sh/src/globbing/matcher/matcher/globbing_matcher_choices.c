/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_matcher_star
*/

#include "globbing.h"
#include "string_utils.h"

#include <string.h>
#include <stdio.h>

static bool is_valid(char *token, char *globbing, char *string)
{
    char *after = strstr(globbing, "}") + 1;
    char *buffer = alloca(sizeof(char) * (strlen(token) + strlen(after) + 1));

    buffer = strcat(strcpy(buffer, token), after);
    return globbing_matcher(buffer, string);
}

bool globbing_matcher_choices(char *globbing, char *string)
{
    char *globing_copy = MY_STRDUPA(globbing) + 1;
    char *token = NULL;

    if (strstr(globbing, "}") == NULL || strstr(globbing, ",") == NULL)
        return globbing_matcher_char(globbing, string);
    (strstr(globing_copy, "}")[0]) = '\0';
    token = strsep(&globing_copy, "{,}");
    while (token != NULL) {
        if (is_valid(token, globbing, string)) {
            return true;
        }
        token = strsep(&globing_copy, "{,}");
    }
    return false;
}
