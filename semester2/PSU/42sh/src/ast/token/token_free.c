/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** tokenizer
*/

#include "token.h"
#include "my_common.h"

#include <stdlib.h>

static void free_literal_token(token_t *token)
{
    char **args = token->token_literal.value;

    for (size_t i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(token->token_literal.value);
}

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_free_value(token_t *token)
{
    if (token->token_type == LITERAL)
        free_literal_token(token);
}

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_free(tokens_t *tokens)
{
    tokens_t *previous_token = NULL;

    while (tokens != NULL) {
        previous_token = tokens;
        tokens = tokens->next;
        token_free_value(&previous_token->token);
        free(previous_token);
    }
}
