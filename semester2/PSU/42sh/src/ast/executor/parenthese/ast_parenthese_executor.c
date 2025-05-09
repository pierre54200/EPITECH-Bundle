/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_parentheses_executor
*/

#include "ast.h"

exitcode_t ast_parentheses_executor(ast_t *self)
{
    return ast_exec(self->left);
}
