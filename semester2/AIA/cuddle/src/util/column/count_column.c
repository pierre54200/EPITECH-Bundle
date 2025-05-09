/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** count_column
*/

#include "dataframe.h"

uint32_t count_column(char *line, const char *separator)
{
    char *dupheader = MY_STRDUPA(line);
    char *token = strsep(&dupheader, separator);
    uint32_t counter = 0;

    while (token != NULL) {
        if (!is_valid_column_name(token))
            return -1;
        counter++;
        token = strsep(&dupheader, separator);
    }
    return counter;
}
