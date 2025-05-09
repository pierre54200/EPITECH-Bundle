/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_or_executor
*/

#include "ast.h"

exitcode_t ast_or_executor(ast_t *self)
{
    exitcode_t code = 0;

    code = ast_exec(self->right);
    if (code == 0) {
        return code;
    }
    return ast_exec(self->left);
}
