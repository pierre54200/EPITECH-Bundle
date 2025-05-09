/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** or_finder
*/

#include "token.h"
#include "alias.h"

bool or_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = LINKER;
    data.token_buffer->token.token_linker.type = OR;
    if (parser_tokens_match(*data.parser_tokens, "||", PARSER_RAW)) {
        alias_reset_usage_state(data.context->aliases, true);
        parser_skip_tokens(data.parser_tokens, 1);
        return true;
    }
    return false;
}
