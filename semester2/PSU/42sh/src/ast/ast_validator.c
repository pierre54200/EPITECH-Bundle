/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_validate
*/

#include "ast.h"

static ast_validator_t find_validator(ast_t *ast)
{
    for (size_t i = 0; i < ast_validator_count; i++) {
        if (!ast_validator[i].resolver(ast)) {
            continue;
        }
        return ast_validator[i];
    }
    return (ast_validator_t){ 0 };
}

bool ast_validate(ast_t *ast)
{
    ast_validator_t validator = find_validator(ast);

    if (validator.validate == NULL || validator.resolver == NULL) {
        return false;
    }
    return validator.validate(ast);
}
