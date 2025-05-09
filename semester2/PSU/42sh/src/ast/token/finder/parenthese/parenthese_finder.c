/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parentheses_finder
*/

#include "token.h"
#include "string_utils.h"
#include <stdio.h>

bool parentheses_open_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = PARENTHESES;
    data.token_buffer->token.token_parentheses.type = OPEN;
    data.token_buffer->token.token_parentheses.status = PARENTHESES_IS_OPEN;
    return parser_tokens_match(*data.parser_tokens, "(", PARSER_RAW);
}

bool parentheses_close_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = PARENTHESES;
    data.token_buffer->token.token_parentheses.type = CLOSE;
    data.token_buffer->token.token_parentheses.status = PARENTHESES_IS_CLOSE;
    return parser_tokens_match(*data.parser_tokens, ")", PARSER_RAW);
}
