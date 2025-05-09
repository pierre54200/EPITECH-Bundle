/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** build_command_node
*/

#include "ast.h"
#include "token.h"
#include "string_utils.h"

static ast_t **find_parenthese(ast_t **root)
{
    ast_t *node;
    ast_t **left;
    ast_t **right;

    if (root == NULL || *root == NULL)
        return NULL;
    node = *root;
    if (NODE_TYPE(node) == PARENTHESES &&
            NODE_TOKEN(node).token_parentheses.status == PARENTHESES_IS_OPEN) {
        return root;
    }
    left = find_parenthese(&node->left);
    if (left != NULL)
        return left;
    right = find_parenthese(&node->right);
    if (right != NULL)
        return right;
    return NULL;
}

ast_t *build_parenthese_node(ast_t **root,
    tokens_t *token, ast_context_t *context)
{
    ast_t *node = calloc(sizeof(ast_t), 1);
    ast_t **stage = find_current_stage(root);

    if (node == NULL) {
        return NULL;
    }
    if (token->token.token_type == PARENTHESES &&
        token->token.token_parentheses.status == PARENTHESES_IS_OPEN) {
        *stage = node;
    } else if (token->token.token_type == PARENTHESES &&
        token->token.token_parentheses.status == PARENTHESES_IS_CLOSE &&
        find_parenthese(root) != NULL) {
        (*find_parenthese(root))->node.token->token.token_parentheses.status =
        PARENTHESES_IS_CLOSE;
    }
    node->context = context;
    node->node.token = token;
    return node;
}
