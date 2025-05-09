/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_write_resolver
*/

#include "ast.h"

bool ast_write_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != IO) {
        return false;
    }
    return NODE_TOKEN(self).token_io.type == WRITE;
}
