/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_add_new_token
*/

#include "parser.h"

#include <stdlib.h>

/**
** @brief Alloc and add a new token to the tokens list
** @param tokens The list.
** @return The new token allocated.
**/
parser_tokens_t *parser_add_new_token(parser_tokens_t *token)
{
    parser_tokens_t *new_token = calloc(sizeof(parser_tokens_t), 1);

    while (token != NULL && token->next != NULL)
        token = token->next;
    if (token != NULL) {
        token->next = new_token;
    }
    return new_token;
}
