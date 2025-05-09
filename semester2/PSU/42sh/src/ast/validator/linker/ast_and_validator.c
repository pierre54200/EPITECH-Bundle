/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_and_validator
*/

#include "ast.h"

bool ast_and_validator(ast_t *self)
{
    if (self->right == NULL)
        return true;
    if (self->left == NULL)
        return false;
    return ast_validate(self->left) && ast_validate(self->right);
}
