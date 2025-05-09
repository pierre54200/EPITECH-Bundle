/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias_string_find
*/

#include "alias.h"
#include "parser.h"

#include <string.h>
#include <stdio.h>
#include <alloca.h>

static bool is_matching(parser_tokens_t *tokens, aliases_t *current)
{
    if (parser_tokens_match(tokens, current->alias.key, PARSER_RAW)) {
        parser_skip_tokens(&tokens, strlen(current->alias.key));
        return tokens == NULL || (tokens->token.type != PARSER_LITERAL
            && alias_is_valid_char(tokens->token.value));
    }
    return false;
}

/**
** @brief Find an alias in the aliases list using a tokens list key
** @param context The context of aliases
** @param tokens The given token list
** @return Return the found aliases data or NULL
**/
alias_t *alias_parser_find(shell_context_t *context, parser_tokens_t *tokens)
{
    aliases_t *current = context->aliases;
    alias_t *match = NULL;

    while (current != NULL) {
        if (match != NULL && strlen(current->alias.key) < strlen(match->key)) {
            current = current->next;
            continue;
        }
        if (is_matching(tokens, current)) {
            match = &current->alias;
        }
        current = current->next;
    }
    return match;
}
