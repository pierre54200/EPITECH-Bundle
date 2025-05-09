/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_builder_raw
*/

#include "parser.h"

#include <stdlib.h>

parser_tokens_t *parser_raw_token_creator(
    shell_context_t *, char **input)
{
    parser_tokens_t *token = calloc(sizeof(parser_tokens_t), 1);

    if (token == NULL) {
        return NULL;
    }
    token->token.value = **input;
    (*input)++;
    token->token.type = PARSER_RAW;
    return token;
}
