/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_builder_uote
*/

#include "parser.h"
#include "string_utils.h"

parser_tokens_t *parser_quote_token_creator(
    shell_context_t *, char **input)
{
    parser_tokens_t *new_token = NULL;
    parser_tokens_t *token = NULL;
    char quote = **input;

    (*input)++;
    while ((**input) != '\0' && **input != quote) {
        new_token = parser_add_new_token(token);
        if (new_token == NULL)
            return NULL;
        if (token == NULL)
            token = new_token;
        new_token->token.type = PARSER_LITERAL;
        new_token->token.value = **input;
        (*input)++;
    }
    if ((**input) != '\0')
        (*input)++;
    return token;
}
