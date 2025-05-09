/*
** EPITECH PROJECT, 2025
** variable_finder.c
** File description:
** find env variable
*/

#include "parser.h"
#include "token.h"
#include "string_utils.h"
#include "my_common.h"
#include "globbing.h"
#include "env.h"

#include <alloca.h>
#include <string.h>
#include <stdio.h>

static bool parser_tokens_match_env(parser_tokens_t *tokens,
    const char *str, parser_token_type_t type)
{
    if (tokens->token.value != '$')
        return false;
    tokens = tokens->next;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (tokens == NULL) {
            return false;
        }
        if (str[i] == tokens->token.value && type == tokens->token.type) {
            tokens = tokens->next;
            continue;
        }
        return false;
    }
    return true;
}

static bool is_matching(parser_tokens_t *tokens, env_t *current)
{
    if (parser_tokens_match_env(tokens, current->key, PARSER_RAW)) {
        parser_skip_tokens(&tokens, strlen(current->key));
        return tokens == NULL || (tokens->token.type != PARSER_LITERAL);
    }
    return false;
}

static env_t *env_parser_find(env_t *env, parser_tokens_t *tokens)
{
    env_t *current = env;
    env_t *match = NULL;

    while (current != NULL) {
        if (match != NULL && strlen(current->key) < strlen(match->key)) {
            current = current->next;
            continue;
        }
        if (is_matching(tokens, current)) {
            match = current;
        }
        current = current->next;
    }
    return match;
}

static void handle_env(token_creation_data_t data, env_t *env)
{
    parser_tokens_t *new_tokens =
        parser_parse(data.context, env->value);
    parser_tokens_t *new_tokens_end = new_tokens;
    parser_tokens_t *after_current_command = NULL;

    if (new_tokens == NULL) {
        return;
    }
    parser_skip_tokens(data.parser_tokens, strlen(env->key));
    for (size_t i = 0; new_tokens_end->next != NULL; i++) {
        new_tokens_end = new_tokens_end->next;
    }
    after_current_command = (*data.parser_tokens)->next;
    (*data.parser_tokens)->next = new_tokens;
    parser_skip_tokens(data.parser_tokens, 1);
    new_tokens_end->next = after_current_command;
    (*data.parser_tokens) = new_tokens;
}

bool env_token_creator(token_creation_data_t data)
{
    env_t *env = env_parser_find(data.context->env, *data.parser_tokens);

    if (env != NULL) {
        handle_env(data, env);
    }
    return false;
}
