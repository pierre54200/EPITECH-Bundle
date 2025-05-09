/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_add_token
*/

#include "parser.h"

/**
** @brief Add token after "token" and return the new last token
** @param token The token.
** @param new_token The new token.
**/
parser_tokens_t *parser_add_token(
    parser_tokens_t *token,
    parser_tokens_t *new_token)
{
    if (token != NULL) {
        token->next = new_token;
    }
    while (new_token->next != NULL)
        new_token = new_token->next;
    return new_token;
}
