/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** literal_finder
*/

#include "parser.h"
#include "token.h"
#include "string_utils.h"
#include "my_common.h"
#include "globbing.h"
#include "alias.h"

#include <alloca.h>
#include <string.h>
#include <stdio.h>

static void handle_alias(token_creation_data_t data, alias_t *alias)
{
    parser_tokens_t *new_tokens =
        parser_parse(data.context, alias->replacement);
    parser_tokens_t *new_tokens_end = new_tokens;
    parser_tokens_t *after_current_command = NULL;

    if (new_tokens == NULL) {
        return;
    }
    parser_skip_tokens(data.parser_tokens, strlen(alias->key) - 1);
    for (size_t i = 0; new_tokens_end->next != NULL; i++) {
        new_tokens_end = new_tokens_end->next;
    }
    after_current_command = (*data.parser_tokens)->next;
    (*data.parser_tokens)->next = new_tokens;
    parser_skip_tokens(data.parser_tokens, 1);
    new_tokens_end->next = after_current_command;
    (*data.parser_tokens) = new_tokens;
}

static bool should_replace(tokens_t *tokens)
{
    if (tokens == NULL)
        return true;
    if (tokens->next == NULL)
        return TOKEN_TYPE(tokens) == LINKER || TOKEN_TYPE(tokens) == SEPARATOR;
    if (tokens->next->next == NULL)
        return tokens->token.token_type == IO &&
            tokens->next->token.token_type == LITERAL;
    while (tokens->next != NULL && TOKEN_TYPE(tokens) == LITERAL)
        tokens = tokens->next;
    if (TOKEN_TYPE(tokens) == LITERAL)
        return false;
    return should_replace(tokens->next);
}

bool alias_token_creator(token_creation_data_t data)
{
    alias_t *alias = alias_parser_find(data.context, *data.parser_tokens);

    if (alias != NULL && alias->usable && should_replace(data.tokens_root)) {
        handle_alias(data, alias);
        alias->usable = false;
        return alias_token_creator(data);
    }
    return false;
}
