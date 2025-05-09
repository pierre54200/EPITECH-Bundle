/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_const
*/

#include "ast.h"

const ast_builder_t ast_builders[] = {
    {SEPARATOR, &build_separator_node},
    {LINKER, &build_linker_node},
    {IO, &build_io_node},
    {LITERAL, &build_literal_node},
    {PARENTHESES, &build_parenthese_node}
};

const size_t ast_builders_count = sizeof(ast_builders) / sizeof(ast_builder_t);

const ast_executor_t ast_executor[] = {
    {&ast_append_resolver, &ast_append_executor},
    {&ast_write_resolver, &ast_write_executor},
    {&ast_send_file_resolver, &ast_send_file_executor},
    {&ast_send_stdin_resolver, &ast_send_stdin_executor},
    {&ast_or_resolver, &ast_or_executor},
    {&ast_and_resolver, &ast_and_executor},
    {&ast_pipe_resolver, &ast_pipe_executor},
    {&ast_literal_resolver, &ast_literal_executor},
    {&ast_fork_resolver, &ast_fork_executor},
    {&ast_separator_resolver, &ast_separator_executor},
    {&ast_parentheses_resolver, &ast_parentheses_executor}
};

const size_t ast_executor_count =
sizeof(ast_executor) / sizeof(ast_executor_t);

const ast_validator_t ast_validator[] = {
    {&ast_append_resolver, &ast_append_validator},
    {&ast_write_resolver, &ast_write_validator},
    {&ast_send_file_resolver, &ast_send_file_validator},
    {&ast_send_stdin_resolver, &ast_send_stdin_validator},
    {&ast_or_resolver, &ast_or_validator},
    {&ast_and_resolver, &ast_and_validator},
    {&ast_pipe_resolver, &ast_pipe_validator},
    {&ast_literal_resolver, &ast_literal_validator},
    {&ast_fork_resolver, &ast_fork_validator},
    {&ast_separator_resolver, &ast_separator_validator},
    {&ast_parentheses_resolver, &ast_parentheses_validator}
};

const size_t ast_validator_count =
sizeof(ast_validator) / sizeof(ast_validator_t);
