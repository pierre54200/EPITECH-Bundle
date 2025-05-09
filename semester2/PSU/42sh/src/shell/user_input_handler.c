/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** user_input_handler
*/

#include "minishell.h"
#include "parser.h"
#include "token.h"
#include "ast.h"
#include "prompt.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void handle_token(shell_context_t *context, tokens_t *tokens)
{
    ast_t *ast = ast_build(context, tokens);

    if (ast_validate(ast)) {
        context->process_exitcode = ast_exec(ast);
        ast_free(ast, ast->context);
    } else {
        fprintf(stderr, "Invalid null command.\n");
        context->process_exitcode = 84;
    }
}

void handle_input(shell_context_t *context, char *input)
{
    tokens_t *tokens = NULL;
    parser_tokens_t *parsed_input = NULL;

    if (input[0] == '#' || input[0] == '\0')
        return;
    parsed_input = parser_parse(context, input);
    if (parsed_input == NULL) {
        shell_stop(context, 1, "Memory allocation error.\n");
        return;
    }
    tokens = tokenizer(context, parsed_input);
    handle_token(context, tokens);
    parser_free(parsed_input);
}

void user_input_handler(shell_context_t *context)
{
    bool has_executed = false;
    char *input = NULL;

    do {
        input = prompt_ask_user(context);
        context->whole_command = input;
        context->timer = time(0);
        if (input == NULL)
            return;
        if (input[0] != '\0') {
            handle_input(context, input);
            has_executed = true;
        }
        free(input);
    } while (!has_executed);
}
