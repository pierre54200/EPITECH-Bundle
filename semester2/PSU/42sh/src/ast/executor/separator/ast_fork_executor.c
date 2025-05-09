/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_and_executor
*/

#include "ast.h"
#include <stdio.h>
#include <string.h>

exitcode_t ast_fork_executor(ast_t *self)
{
    int fpid = fork();

    switch (fpid) {
        case -1:
            return -1;
        case 0:
            self->context->shell_context->is_wait = false;
            break;
        default:
            add_job(&self->context->shell_context->jobs, fpid,
                strdup(self->context->shell_context->whole_command));
            return ast_exec(self->left);
    }
    return ast_exec(self->right);
}
