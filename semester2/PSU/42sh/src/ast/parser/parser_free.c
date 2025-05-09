/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parser
*/

#include "parser.h"

#include <stdlib.h>

/**
** @brief Free the parsed_data array.
** @param parsed_tokens The parsed data to free.
**/
void parser_free(parser_tokens_t *parsed_tokens)
{
    parser_tokens_t *next = NULL;

    if (parsed_tokens == NULL) {
        return;
    }
    while (parsed_tokens != NULL) {
        next = parsed_tokens->next;
        free(parsed_tokens);
        parsed_tokens = next;
    }
}
