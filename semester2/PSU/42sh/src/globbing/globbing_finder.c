/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing_loader
*/

#include "globbing.h"

static bool is_choices(
    parser_tokens_t *tokens, size_t string_len,
    char flags)
{
    char value = 0;
    parser_token_type_t type = 0;

    if (flags == 0b111)
        return true;
    if (string_len == 0)
        return false;
    value = tokens->token.value;
    type = tokens->token.type;
    if (type != PARSER_RAW)
        return is_choices(tokens->next, string_len - 1, flags);
    if (value == '{' && flags == 0b000)
        flags = 0b001;
    if (value == ',' && flags == 0b001)
        flags = 0b011;
    if (value == '}' && flags == 0b011)
        flags = 0b111;
    return is_choices(tokens->next, string_len - 1, flags);
}

/**
** @brief Use to find if a list of token contains a globbing.
** @param tokens The token list that will be searched
** @param string_len The amount of token that will be read
** @return True if the string contain a globbing
**/
bool globbing_finder(parser_tokens_t *tokens, size_t string_len)
{
    char value = 0;
    parser_token_type_t type = 0;

    if (string_len == 0 || tokens == NULL) {
        return false;
    }
    value = tokens->token.value;
    type = tokens->token.type;
    if (type != PARSER_RAW) {
        return globbing_finder(tokens->next, string_len - 1);
    }
    if (value == '*' || value == '?' || is_choices(tokens, string_len, 0)) {
        return true;
    }
    return globbing_finder(tokens->next, string_len - 1);
}
