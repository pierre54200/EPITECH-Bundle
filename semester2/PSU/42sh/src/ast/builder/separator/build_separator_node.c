/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** build_command_node
*/

#include "ast.h"
#include "token.h"
#include "string_utils.h"

static ast_t **find_target_stage(ast_t **root)
{
    ast_t **target_stage = root;

    while (*target_stage != NULL) {
        if (NODE_TYPE(*target_stage) == SEPARATOR) {
            target_stage = &(*target_stage)->left;
            continue;
        }
        break;
    }
    return target_stage;
}

ast_t *build_separator_node(ast_t **root,
    tokens_t *token, ast_context_t *context)
{
    ast_t *node = calloc(sizeof(ast_t), 1);
    ast_t **stage = find_target_stage(root);

    if (node == NULL) {
        return NULL;
    }
    node->node.token = token;
    node->context = context;
    node->right = *stage;
    *stage = node;
    return node;
}
