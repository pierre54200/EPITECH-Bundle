/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** tokenizer
*/

#include "token.h"
#include "parser.h"
#include "my_common.h"

#include <string.h>

static void add_token(tokens_t **tokens, tokens_t *new_token)
{
    tokens_t *last_token = *tokens;

    if (last_token == NULL) {
        (*tokens) = new_token;
        return;
    }
    while (last_token->next != NULL)
        last_token = last_token->next;
    last_token->next = new_token;
}

static tokens_t *load_token(shell_context_t *context, tokens_t *tokens,
    parser_tokens_t **ptokens, bool *error)
{
    tokens_t *new_token = malloc(sizeof(tokens_t));
    token_creation_data_t data = {context, tokens, new_token, ptokens, error};

    if (new_token == NULL)
        return NULL;
    for (size_t i = 0; i < token_finders_count; i++) {
        memset(new_token, 0, sizeof(tokens_t));
        (*error) = false;
        if (!token_finders[i].token_creator(data))
            continue;
        if (*error)
            break;
        return data.token_buffer;
    }
    free(new_token);
    return NULL;
}

/**
** Use to transform an input to token.
** @param input The string array to tokenize.
** @return The resulting tokens.
**/
tokens_t *tokenizer(shell_context_t *context, parser_tokens_t *parser_tokens)
{
    tokens_t *tokens = NULL;
    tokens_t *current_token = NULL;
    bool error = false;

    while (parser_tokens != NULL) {
        current_token = load_token(context, tokens, &parser_tokens, &error);
        if (error) {
            token_free(tokens);
            tokens = NULL;
            break;
        }
        if (current_token != NULL) {
            add_token(&tokens, current_token);
        }
        parser_tokens = parser_tokens->next;
    }
    return tokens;
}
