/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_send_stdin_validator
*/

#include "ast.h"

bool ast_send_stdin_validator(ast_t *self)
{
    if (self->left == NULL || self->right == NULL) {
        return false;
    }
    if (NODE_TYPE(self->left) != LITERAL ||
            NODE_TYPE(self->right) != LITERAL) {
        return false;
    }
    return ast_validate(self->left) && ast_validate(self->right);
}
