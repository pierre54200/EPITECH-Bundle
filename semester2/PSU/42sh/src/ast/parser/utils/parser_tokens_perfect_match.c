/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_tokens_match
*/

#include "parser.h"

/**
** @brief Check if a multiple token match perfectly a string
** @param tokens The list.
** @param str The string to match for.
** @param type The type of the tokens to be
** @return True if it's matching False else.
**/
bool parser_tokens_perfect_match(parser_tokens_t *tokens,
    const char *str, parser_token_type_t type)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (tokens == NULL) {
            return false;
        }
        if (str[i] == tokens->token.value && type == tokens->token.type) {
            tokens = tokens->next;
            continue;
        }
        return false;
    }
    return tokens == NULL;
}
