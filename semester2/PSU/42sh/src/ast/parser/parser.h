/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parser
*/

#ifndef PARSER_H_
    #define PARSER_H_

    #include <stdint.h>
    #include <stddef.h>
    #include <stdbool.h>

    #include "minishell.h"

typedef enum parser_token_type {
    PARSER_RAW,
    PARSER_LITERAL
} parser_token_type_t;

typedef struct parser_token {
    char value;
    parser_token_type_t type;
} parser_token_t;

typedef struct parser_tokens {
    parser_token_t token;
    struct parser_tokens *next;
} parser_tokens_t;

typedef struct parser_token_builder {
    char *format;
    parser_tokens_t *(*builder)(shell_context_t *context, char **input);
} parser_token_builder_t;

extern const parser_token_builder_t parser_token_builders[];
extern const size_t token_builders_count;

/**
** @brief Find the token finder based on a string that contain at start the
** format.
** @param format The format to find.
**/
parser_token_builder_t parser_find_token_builder(char *format);

parser_tokens_t *parser_raw_token_creator(shell_context_t *, char **);
parser_tokens_t *parser_escape_token_creator(shell_context_t *, char **);
parser_tokens_t *parser_quote_token_creator(shell_context_t *, char **);
parser_tokens_t *parser_backtick_token_creator(shell_context_t *, char **);

/**
** @brief Used to parser the raw user input,
**  the raw user input is the command entered by the user,
**  this function is used to parse this output by replacing escaped char,
**  input string and other things like this.
** Escaped char: \052 -> '*' or \0142 -> 'b'
**               \"   -> '"' or \'    -> ''' | [Hi \'-\'] -> [Hi '-']
**    <!> Every char aren't processed here (\&, \;, ...)
** Input string: "Hello world" -> "Hello world" != "Hello" "World"
**               'Hello world' -> "Hello world" != "Hello" "World"
** @param raw_input The raw input.
** @return The parsed input.
**/
parser_tokens_t *parser_parse(shell_context_t *context, char *raw_input);

/**
** @brief Free the parsed_data array.
** @param tokens The parsed data to free.
**/
void parser_free(parser_tokens_t *tokens);

/**
** @brief Dump a parser tokens list
** @param tokens The parsed tokens to dump.
**/
void parser_dump(parser_tokens_t *tokens);

/**
** @brief Add token after "token" and return the new last token
** @param token The token.
** @param new_token The new token.
**/
parser_tokens_t *parser_add_token(
    parser_tokens_t *token,
    parser_tokens_t *new_token);

/**
** @brief Alloc and add a new token to the tokens list
** @param tokens The list.
** @return The new token allocated.
**/
parser_tokens_t *parser_add_new_token(parser_tokens_t *tokens);

/**
** @brief Check if a multiple token match a string
** @param tokens The list.
** @param str The string to match for.
** @param type The type of the tokens to be
** @return True if it's matching False else.
**/
bool parser_tokens_match(parser_tokens_t *tokens,
    const char *str, parser_token_type_t type);

/**
** @brief Check if a multiple token match perfectly a string
** @param tokens The list.
** @param str The string to match for.
** @param type The type of the tokens to be
** @return True if it's matching False else.
**/
bool parser_tokens_perfect_match(parser_tokens_t *tokens,
    const char *str, parser_token_type_t type);

/**
** @brief Skip n tokens of a given list.
** @param tokens The list.
** @param n The amount of tokens to skip.
** @return True if has reach the end..
**/
bool parser_skip_tokens(parser_tokens_t **tokens, size_t n);

#endif /* !PARSER_H_ */
