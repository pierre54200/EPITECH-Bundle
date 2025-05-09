/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_pipe_resolver
*/

#include "ast.h"

bool ast_pipe_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != LINKER) {
        return false;
    }
    return NODE_TOKEN(self).token_linker.type == PIPE;
}
