/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** token_const
*/

#include "token.h"

const token_finder_t token_finders[] = {
    {LINKER, &or_token_creator},
    {LINKER, &and_token_creator},
    {LINKER, &pipe_token_creator},
    {IO, &append_token_creator},
    {IO, &write_token_creator},
    {IO, &set_delimiter_token_creator},
    {IO, &send_input_token_creator},
    {SEPARATOR, &semicolon_token_creator},
    {SEPARATOR, &fork_token_creator},
    {LITERAL, &env_token_creator},
    {LITERAL, &alias_token_creator},
    {LITERAL, &literal_token_creator},
    {PARENTHESES, &parentheses_open_token_creator},
    {PARENTHESES, &parentheses_close_token_creator}
};

const size_t token_finders_count =
sizeof(token_finders) / sizeof(token_finder_t);
