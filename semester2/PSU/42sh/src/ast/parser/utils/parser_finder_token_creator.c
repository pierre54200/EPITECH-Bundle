/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_finder_token_creator
*/

#include "parser.h"
#include "my_common.h"

#include <string.h>

/**
** @brief Find the token finder based on a string that contain at start the
** format.
** @param format The format to find.
**/
parser_token_builder_t parser_find_token_builder(char *format)
{
    parser_token_builder_t found = { 0 };
    parser_token_builder_t builder = { 0 };

    for (size_t i = 0; i < token_builders_count; i++) {
        builder = parser_token_builders[i];
        if (found.format != 0 && strlen(found.format) > strlen(builder.format))
            continue;
        if (strncmp(format, builder.format, strlen(builder.format)) == 0) {
            found = builder;
        }
    }
    return found;
}
