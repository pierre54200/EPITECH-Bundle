/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** build_io_node
*/

#include "ast.h"
#include "token.h"
#include "string_utils.h"

static void update_link(ast_t *node, ast_t *stage)
{
    if (stage == NULL) {
        return;
    }
    node->right = stage;
}

ast_t *build_io_node(ast_t **root,
    tokens_t *token, ast_context_t *context)
{
    ast_t *node = calloc(sizeof(ast_t), 1);
    ast_t **stage = find_current_stage(root);

    if (node == NULL) {
        return NULL;
    }
    update_link(node, *stage);
    node->context = context;
    node->node.token = token;
    *stage = node;
    return node;
}
