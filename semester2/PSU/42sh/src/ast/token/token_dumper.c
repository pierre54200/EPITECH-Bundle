/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** tokenizer
*/

#include "token.h"

#include <stdio.h>

static void dump_literal(token_t tkn)
{
    printf(" [LITERAL] {");
    for (size_t i = 0; tkn.token_literal.value[i] != NULL; i++) {
        printf("%s", tkn.token_literal.value[i]);
        if (tkn.token_literal.value[i + 1] != NULL) {
            printf(", ");
        }
    }
    printf("}");
}

/**
** Use to dump token.
** @param token The token.
**/
void token_dump_single(uint32_t id, token_t tkn)
{
    printf("[%u] %i", id, tkn.token_type);
    if (tkn.token_type == LITERAL)
        dump_literal(tkn);
    if (tkn.token_type == IO)
        printf(" [IO] {%i}", tkn.token_io.type);
    if (tkn.token_type == SEPARATOR)
        printf(" [SEPARATOR] {%i}", tkn.token_separator.type);
    if (tkn.token_type == LINKER)
        printf(" [LINKER] {%i}", tkn.token_linker.type);
    if (tkn.token_type == PARENTHESES)
        printf(" [PARENTHESES] {%i}", tkn.token_parentheses.status);
    printf("\n");
}

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_dump(tokens_t *tokens)
{
    for (uint32_t id = 0; tokens != NULL; id++) {
        token_dump_single(id, tokens->token);
        tokens = tokens->next;
    }
}
