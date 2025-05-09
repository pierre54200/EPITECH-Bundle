/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** pipe_finder
*/

#include "token.h"
#include "alias.h"

bool pipe_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = LINKER;
    data.token_buffer->token.token_linker.type = PIPE;
    if (parser_tokens_match(*data.parser_tokens, "|", PARSER_RAW)) {
        alias_reset_usage_state(data.context->aliases, true);
        return true;
    }
    return false;
}
