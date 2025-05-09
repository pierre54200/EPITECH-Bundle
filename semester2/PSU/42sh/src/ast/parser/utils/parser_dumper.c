/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parser
*/

#include "parser.h"
#include "string_utils.h"

#include <stdio.h>

/**
** @brief Dump a parser tokens list
** @param tokens The parsed tokens to dump.
**/
void parser_dump(parser_tokens_t *tokens)
{
    if (tokens == NULL) {
        return;
    }
    printf("[%i] -> %c\n", tokens->token.type, tokens->token.value);
    parser_dump(tokens->next);
}
