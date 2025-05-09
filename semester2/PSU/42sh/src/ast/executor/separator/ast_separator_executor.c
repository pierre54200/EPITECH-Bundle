/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_and_executor
*/

#include "ast.h"

exitcode_t ast_separator_executor(ast_t *self)
{
    ast_exec(self->right);
    return ast_exec(self->left);
}
