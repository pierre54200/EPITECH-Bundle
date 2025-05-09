/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_separator_validator
*/

#include "ast.h"

bool ast_separator_validator(ast_t *self)
{
    if (self->right != NULL && !ast_validate(self->right)) {
        return false;
    }
    if (self->left != NULL && !ast_validate(self->left)) {
        return false;
    }
    return true;
}
