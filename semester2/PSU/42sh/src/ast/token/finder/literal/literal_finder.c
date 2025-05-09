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

static bool is_other_token(shell_context_t *context, parser_tokens_t *ptokens)
{
    tokens_t *new_token = malloc(sizeof(tokens_t));
    bool is_other = false;
    bool error = false;
    token_creation_data_t data = {context, NULL, new_token, &ptokens, &error};

    if (new_token == NULL) {
        return false;
    }
    for (size_t i = 0; i < token_finders_count; i++) {
        memset(new_token, 0, sizeof(tokens_t));
        error = false;
        if (token_finders[i].token_type == LITERAL ||
                !token_finders[i].token_creator(data) || error) {
            continue;
        }
        is_other = true;
        break;
    }
    token_free(new_token);
    return is_other;
}

static bool is_string_token(shell_context_t *context,
    parser_tokens_t *parser_tokens)
{
    char value = 0;

    if (parser_tokens == NULL)
        return false;
    value = parser_tokens->token.value;
    if (parser_tokens->token.type == PARSER_LITERAL)
        return true;
    if (is_other_token(context, parser_tokens))
        return false;
    if (parser_tokens->token.type == PARSER_RAW)
        return value != ' ' && value != '\n' && value != '\t';
    return false;
}

static size_t find_string_length(shell_context_t *context,
    parser_tokens_t *parser_tokens)
{
    if (!is_string_token(context, parser_tokens)) {
        return 0;
    }
    return find_string_length(context, parser_tokens->next) + 1;
}

static char *load_string_buffer(
    size_t buffer_len, bool *error)
{
    char *buffer = NULL;

    if (buffer_len == 0)
        return NULL;
    buffer = calloc(sizeof(char), buffer_len + 1);
    if (buffer == NULL) {
        *error = true;
        return NULL;
    }
    return buffer;
}

static void create_string(shell_context_t *context,
    parser_tokens_t **tokens, bool *error, char ***array)
{
    size_t buffer_len = find_string_length(context, *tokens);
    char *buffer = load_string_buffer(buffer_len, error);
    bool is_globing = globbing_finder(*tokens, buffer_len);

    if (buffer == NULL)
        return;
    for (size_t i = 0; i < buffer_len; i++) {
        buffer[i] = (*tokens)->token.value;
        DO_IF((i + 1) != buffer_len, parser_skip_tokens(tokens, 1));
    }
    if (is_globing && globbing_load(buffer, array)) {
        free(buffer);
        return;
    }
    buffer[buffer_len] = '\0';
    (*array)[0] = buffer;
}

bool literal_token_creator(token_creation_data_t data)
{
    data.token_buffer->token.token_type = LITERAL;
    data.token_buffer->token.token_literal.value = calloc(sizeof(char *), 2);
    if (data.token_buffer->token.token_literal.value == NULL) {
        (*data.error) = true;
        return false;
    }
    create_string(data.context, data.parser_tokens, data.error,
        &data.token_buffer->token.token_literal.value);
    if (data.token_buffer->token.token_literal.value[0] == 0 || *data.error) {
        free(data.token_buffer->token.token_literal.value);
        return false;
    }
    return true;
}
