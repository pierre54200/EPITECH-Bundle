/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parser
*/

#include "parser.h"
#include "string_utils.h"

static parser_tokens_t *build_token(shell_context_t *context, char **raw_input)
{
    parser_token_builder_t builder = parser_find_token_builder(*raw_input);

    if (builder.builder == NULL) {
        return NULL;
    }
    return builder.builder(context, raw_input);
}

/**
** @brief Used to parser the raw user input,
**  the raw user input is the command entered by the user,
**  this function is used to parse this output by replacing escaped char,
**  input string and other things like this.
** Escaped char: \052 -> '*' or \0142 -> 'b'
**               \"   -> '"' or \'    -> ''' | [Hi \'-\'] -> [Hi '-']
** Input string: "Hello world" -> "Hello world" != "Hello" "World"
**               'Hello world' -> "Hello world" != "Hello" "World"
** +--------+
** | To see |
** Separator:    "echo a&&echo b" -> "echo" "a" "&&" "echo" "b"
**               "echo a||echo b" -> "echo" "a" "||" "echo" "b"
**               "echo a&"   -> "echo" "a" "&"
**               "echo a\&&" -> "echo" "a&" "&"
** @param raw_input The raw input.
** @return The parsed input.
**/
parser_tokens_t *parser_parse(shell_context_t *context, char *raw_input)
{
    parser_tokens_t *head = NULL;
    parser_tokens_t *tail = NULL;
    parser_tokens_t *new_token = NULL;

    if (raw_input == NULL) {
        return NULL;
    }
    while (raw_input != NULL && *raw_input != '\0') {
        new_token = build_token(context, &raw_input);
        if (new_token == NULL) {
            continue;
        }
        if (head == NULL) {
            head = new_token;
        }
        tail = parser_add_token(tail, new_token);
    }
    return head;
}
