/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_builder
*/

#include "ast.h"
#include "string_utils.h"
#include "my_common.h"

#include <stdio.h>

static bool add_node(
    ast_t **root, tokens_t *token,
    ast_context_t *context)
{
    for (size_t i = 0; i < ast_builders_count; i++) {
        if (ast_builders[i].type != token->token.token_type) {
            continue;
        }
        return ast_builders[i].builder(root, token, context) != NULL;
    }
    return true;
}

ast_t *ast_build(shell_context_t *shell_context, tokens_t *tokens)
{
    ast_context_t *context = calloc(sizeof(ast_context_t), 1);
    tokens_t *next = NULL;
    ast_t *root = NULL;

    if (context == NULL)
        return NULL;
    context->shell_context = shell_context;
    while (tokens != NULL) {
        next = tokens->next;
        if (!add_node(&root, tokens, context)) {
            ast_free(root, context);
            return NULL;
        }
        tokens = next;
    }
    FREE_IF(root == NULL, context);
    return root;
}
