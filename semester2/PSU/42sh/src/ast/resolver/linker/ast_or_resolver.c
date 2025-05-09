/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_or_resolver
*/

#include "ast.h"

bool ast_or_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != LINKER) {
        return false;
    }
    return NODE_TOKEN(self).token_linker.type == OR;
}
