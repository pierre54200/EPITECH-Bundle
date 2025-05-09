/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_fork_validator
*/

#include "ast.h"

bool ast_fork_validator(ast_t *self)
{
    if (self->right == NULL) {
        return false;
    }
    if (!ast_validate(self->right)) {
        return false;
    }
    if (self->left != NULL && !ast_validate(self->left)) {
        return false;
    }
    return true;
}
