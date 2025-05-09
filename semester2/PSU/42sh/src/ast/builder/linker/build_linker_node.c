/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** build_command_node
*/

#include "ast.h"
#include "token.h"
#include "string_utils.h"

static ast_t **jaipasdideepourlenom(ast_t **root)
{
    if (root == NULL || (*root) == NULL)
        return root;
    if (NODE_TYPE(*root) == LINKER || NODE_TYPE(*root) == SEPARATOR)
        return find_current_stage(&(*root)->left);
    if ((*root)->node.token->token.token_type == PARENTHESES &&
    (*root)->node.token->token.token_parentheses.status ==
    PARENTHESES_IS_OPEN) {
        return find_current_stage(&(*root)->left);
    }
    return root;
}

static void update_link(ast_t *node, ast_t *stage)
{
    if (stage == NULL) {
        return;
    }
    node->right = stage;
}

ast_t *build_linker_node(ast_t **root,
    tokens_t *token, ast_context_t *context)
{
    ast_t *node = calloc(sizeof(ast_t), 1);
    ast_t **stage = jaipasdideepourlenom(root);

    if (node == NULL) {
        return NULL;
    }
    update_link(node, *stage);
    node->context = context;
    node->node.token = token;
    *stage = node;
    return node;
}
