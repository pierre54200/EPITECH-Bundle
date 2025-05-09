/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** build_command_node
*/

#include "ast.h"
#include "token.h"
#include "string_utils.h"

#include <string.h>

static ast_t **find_target_stage(ast_t **root)
{
    ast_t **target_stage = find_current_stage(root);

    if (*target_stage == NULL) {
        return target_stage;
    }
    if (NODE_TYPE(*target_stage) == IO) {
        if ((*target_stage)->left != NULL) {
            return &(*target_stage)->right;
        }
        return &(*target_stage)->left;
    }
    return target_stage;
}

static bool merge_token(tokens_t *dest, tokens_t *token)
{
    if (dest == NULL) {
        return false;
    }
    for (size_t i = 0; token->token.token_literal.value[i] != NULL; i++) {
        dest->token.token_literal.value = add_to_array(
            dest->token.token_literal.value,
            token->token.token_literal.value[i]);
    }
    token->next = NULL;
    token_free(token);
    return dest->token.token_literal.value != NULL;
}

ast_t *build_literal_node(ast_t **root,
    tokens_t *token, ast_context_t *context)
{
    ast_t **stage = find_target_stage(root);

    if ((*stage) == NULL) {
        *stage = calloc(sizeof(ast_t), 1);
        (*stage)->context = context;
        (*stage)->node.token = token;
        return *stage;
    }
    if (!merge_token((*stage)->node.token, token)) {
        return NULL;
    }
    return *stage;
}
