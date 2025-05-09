/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_builder
*/

#include "ast.h"
#include "token.h"

static void dump(ast_t *ast, uint32_t stage)
{
    if (ast == NULL) {
        return;
    }
    token_dump_single(stage, ast->node.token->token);
    dump(ast->right, stage + 1);
    dump(ast->left, stage + 1);
}

void ast_dump(ast_t *ast)
{
    dump(ast, 0);
}
