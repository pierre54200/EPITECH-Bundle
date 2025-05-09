/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** token_const
*/

#include "parser.h"

const parser_token_builder_t parser_token_builders[] = {
    {"\\", &parser_escape_token_creator},
    {"", &parser_raw_token_creator},
    {"\"", &parser_quote_token_creator},
    {"\'", &parser_quote_token_creator},
    {"`", &parser_backtick_token_creator}
};

const size_t token_builders_count =
sizeof(parser_token_builders) / sizeof(parser_token_builder_t);
