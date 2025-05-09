/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** set_delimiter
*/

#include "token.h"

bool set_delimiter_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = IO;
    data.token_buffer->token.token_io.type = SEND_STDIN;
    if (parser_tokens_match(*data.parser_tokens, "<<", PARSER_RAW)) {
        parser_skip_tokens(data.parser_tokens, 1);
        return true;
    }
    return false;
}
