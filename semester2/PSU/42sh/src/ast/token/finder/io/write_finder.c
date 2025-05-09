/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** write_finder
*/

#include "token.h"

bool write_token_creator(token_creation_data_t data)
{
    if (data.parser_tokens == NULL || (*data.parser_tokens) == NULL) {
        return false;
    }
    data.token_buffer->token.token_type = IO;
    data.token_buffer->token.token_io.type = WRITE;
    return parser_tokens_match(*data.parser_tokens, ">", PARSER_RAW);
}
