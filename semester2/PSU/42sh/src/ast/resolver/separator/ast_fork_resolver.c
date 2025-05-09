/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_fork_resolver
*/

#include "ast.h"

bool ast_fork_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != SEPARATOR) {
        return false;
    }
    return NODE_TOKEN(self).token_separator.type == FORK;
}
