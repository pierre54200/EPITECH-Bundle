/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_append_resolver
*/

#include "ast.h"

bool ast_append_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != IO) {
        return false;
    }
    return NODE_TOKEN(self).token_io.type == APPEND;
}
