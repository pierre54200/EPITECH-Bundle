/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_builder
*/

#include "ast.h"

static void free_node(ast_t *node)
{
    if (node == NULL) {
        return;
    }
    free_node(node->right);
    free_node(node->left);
    token_free_value(&node->node.token->token);
    free(node->node.token);
    free(node);
}

void ast_free(ast_t *ast, ast_context_t *context)
{
    if (ast == NULL) {
        return;
    }
    free(context);
    free_node(ast);
}
