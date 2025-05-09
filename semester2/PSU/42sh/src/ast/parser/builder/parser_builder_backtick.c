/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** parser_builder_raw
*/

#include "parser.h"
#include "token.h"
#include "my_common.h"
#include "ast.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *create_other_command(char **input)
{
    size_t i = 0;
    char *command = NULL;
    char quote = **input;

    (*input)++;
    while ((**input) != '\0' && **input != quote) {
        command = realloc(command, sizeof(char) * (i + 2));
        command[i] = **input;
        command[i + 1] = '\0';
        i++;
        (*input)++;
    }
    if ((**input) != '\0')
        (*input)++;
    return command;
}

static parser_tokens_t *convert_to_token(char *output)
{
    parser_tokens_t *new_token = NULL;
    parser_tokens_t *token = NULL;

    while (*output) {
        new_token = parser_add_new_token(token);
        if (new_token == NULL)
            return token;
        if (token == NULL)
            token = new_token;
        new_token->token.type = PARSER_LITERAL;
        new_token->token.value = *output;
        output++;
    }
    return token;
}

static char *read_buffer(int fd)
{
    size_t total_size = 0;
    char tmp_buffer[64];
    char *buffer = NULL;
    size_t bytes_read = read(fd, tmp_buffer, 64);

    while (bytes_read > 0) {
        buffer = realloc(buffer, total_size + bytes_read + 1);
        if (buffer == NULL)
            return NULL;
        memcpy(buffer + total_size, tmp_buffer, bytes_read);
        total_size += bytes_read;
        buffer[total_size] = '\0';
        bytes_read = read(fd, tmp_buffer, 64);
    }
    close(fd);
    if (buffer == NULL)
        return NULL;
    return buffer;
}

static void execute_command(shell_context_t *context, char *command)
{
    parser_tokens_t *parsed_input = NULL;
    tokens_t *tokens = NULL;
    ast_t *ast = NULL;

    parsed_input = parser_parse(context, command);
    if (parsed_input == NULL)
        return;
    tokens = tokenizer(context, parsed_input);
    ast = ast_build(context, tokens);
    if (ast_validate(ast))
        ast_exec(ast);
    ast_free(ast, ast->context);
    parser_free(parsed_input);
}

static char *catch_command_output(shell_context_t *context, char *command)
{
    int stdout_copy = 0;
    int pipefd[2] = { 0 };

    if (pipe(pipefd) == -1)
        return NULL;
    stdout_copy = dup(STDOUT_FD);
    dup2(pipefd[1], STDOUT_FD);
    close(pipefd[1]);
    execute_command(context, command);
    fflush(stdout);
    dup2(stdout_copy, STDOUT_FD);
    close(stdout_copy);
    return read_buffer(pipefd[0]);
}

parser_tokens_t *parser_backtick_token_creator(
    shell_context_t *context, char **input)
{
    char *command = create_other_command(input);
    char *output = NULL;
    parser_tokens_t *token = NULL;

    if (command == NULL)
        return NULL;
    output = catch_command_output(context, command);
    free(command);
    if (output == NULL)
        return NULL;
    for (size_t i = 0; output[i]; ++i)
        output[i] = output[i] == '\n' ? ' ' : output[i];
    token = convert_to_token(output);
    free(output);
    return token;
}
