/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_find_stage
*/

#include "ast.h"

ast_t **find_current_stage(ast_t **root)
{
    if (root == NULL || (*root) == NULL)
        return root;
    if (NODE_TYPE(*root) == LINKER || NODE_TYPE(*root) == SEPARATOR)
        return find_current_stage(&(*root)->left);
    if ((*root)->node.token->token.token_type == PARENTHESES &&
    NODE_TOKEN(*root).token_parentheses.status == PARENTHESES_IS_OPEN) {
        return find_current_stage(&(*root)->left);
    } else if ((*root)->node.token->token.token_type == PARENTHESES &&
    NODE_TOKEN(*root).token_parentheses.status == PARENTHESES_IS_CLOSE){
        return find_current_stage(&(*root)->right);
    }
    return root;
}
