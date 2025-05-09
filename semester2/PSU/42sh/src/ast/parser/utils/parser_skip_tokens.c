/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_skip_tokens
*/

#include "parser.h"

/**
** @brief Skip n tokens of a given list.
** @param tokens The list.
** @param n The amount of tokens to skip.
** @return True if has reach the end..
**/
bool parser_skip_tokens(parser_tokens_t **parser_tokens, size_t n)
{
    if (parser_tokens == NULL) {
        return true;
    }
    for (size_t i = 0; i != n; i++) {
        if ((*parser_tokens) == NULL) {
            break;
        }
        (*parser_tokens) = (*parser_tokens)->next;
    }
    return (*parser_tokens) == NULL;
}
