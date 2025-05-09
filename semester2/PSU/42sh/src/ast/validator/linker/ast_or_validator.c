/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_or_validator
*/

#include "ast.h"

bool ast_or_validator(ast_t *self)
{
    if (self->left == NULL || self->right == NULL) {
        return false;
    }
    return ast_validate(self->left) && ast_validate(self->right);
}
