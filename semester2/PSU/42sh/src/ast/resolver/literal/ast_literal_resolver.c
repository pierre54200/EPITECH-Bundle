/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_literal_resolver
*/

#include "ast.h"

bool ast_literal_resolver(ast_t *self)
{
    if (self == NULL) {
        return false;
    }
    return self->node.token->token.token_type == LITERAL;
}
