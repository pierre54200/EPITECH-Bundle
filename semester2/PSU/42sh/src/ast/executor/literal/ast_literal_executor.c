/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_literal_executor
*/

#include "ast.h"
#include "shell_command.h"
#include "string_utils.h"

exitcode_t ast_literal_executor(ast_t *self)
{
    exitcode_t code = 0;

    code = execute_command(self->context->shell_context,
        NODE_TOKEN(self).token_literal.value);
    return code;
}
