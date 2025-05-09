/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_parenthese_resolver
*/

#include "ast.h"

bool ast_parentheses_resolver(ast_t *self)
{
    if (self == NULL || NODE_TYPE(self) != PARENTHESES) {
        return false;
    }
    return NODE_TOKEN(self).token_type == PARENTHESES;
}
