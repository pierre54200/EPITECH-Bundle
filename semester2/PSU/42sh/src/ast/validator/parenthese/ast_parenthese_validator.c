/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_parentheses_validator
*/

#include "ast.h"

bool ast_parentheses_validator(ast_t *self)
{
    if (self->left == NULL || self->right != NULL ||
    self->node.token->token.token_parentheses.status != PARENTHESES_IS_CLOSE) {
        return false;
    }
    return ast_validate(self->left);
}
