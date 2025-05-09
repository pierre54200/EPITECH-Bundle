/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** mytokenizer
*/

#ifndef MYTOKENIZER_H
    #define MYTOKENIZER_H

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdint.h>

    #include "parser.h"

    #define TOKEN_TYPE(t) (tokens->token.token_type)
    #define PARENTHESES_IS_OPEN 1
    #define PARENTHESES_IS_CLOSE 0

typedef enum {
    SEPARATOR,
    LITERAL,
    IO,
    LINKER,
    PARENTHESES
} token_type_t;

/*********************/
/* PARENTHESES TOKEN */
/*********************/

typedef enum {
    OPEN,
    CLOSE
} parentheses_type_t;

typedef struct token_parentheses {
    bool status;
    parentheses_type_t type;
} token_parentheses_t;

/*****************/
/* LITERAL TOKEN */
/*****************/

typedef struct token_literal {
    char **value;
} token_literal_t;

/****************/
/* LINKER TOKEN */
/****************/

typedef enum {
    AND,
    OR,
    PIPE
} linker_type_t;

typedef struct token_linker {
    linker_type_t type;
} token_linker_t;

/*******************/
/* SEPARATOR TOKEN */
/*******************/

typedef enum {
    SEMICOLON,
    FORK
} separator_type_t;

typedef struct token_separator {
    separator_type_t type;
} token_separator_t;

/************/
/* IO TOKEN */
/************/

typedef enum {
    WRITE, APPEND,
    SEND_FILE, SEND_STDIN
} io_type_t;

typedef struct token_io {
    io_type_t type;
} token_io_t;

/*********/
/* TOKEN */
/*********/

typedef struct {
    token_type_t token_type;
    union {
        token_literal_t token_literal;
        token_linker_t token_linker;
        token_separator_t token_separator;
        token_io_t token_io;
        token_parentheses_t token_parentheses;
    };
} token_t;

typedef struct tokens {
    token_t token;
    struct tokens *next;
} tokens_t;

/****************/
/* TOKEN FINDER */
/****************/

typedef struct {
    shell_context_t *context;
    tokens_t *tokens_root;
    tokens_t *token_buffer;
    parser_tokens_t **parser_tokens;
    bool *error;
} token_creation_data_t;

/**
** @brief token_creator function should return true if the input is valid.
**/
typedef struct {
    token_type_t token_type;
    bool (*token_creator)(token_creation_data_t data);
} token_finder_t;

// IO FINDER
bool append_token_creator(token_creation_data_t data);
bool write_token_creator(token_creation_data_t data);
bool send_input_token_creator(token_creation_data_t data);
bool set_delimiter_token_creator(token_creation_data_t data);

// SEPARATOR
bool semicolon_token_creator(token_creation_data_t data);
bool fork_token_creator(token_creation_data_t data);

// LINKER
bool and_token_creator(token_creation_data_t data);
bool or_token_creator(token_creation_data_t data);
bool pipe_token_creator(token_creation_data_t data);

// LITERAL FINDER
bool literal_token_creator(token_creation_data_t data);
bool alias_token_creator(token_creation_data_t data);
bool env_token_creator(token_creation_data_t data);

// PARENTHESES
bool parentheses_open_token_creator(token_creation_data_t data);
bool parentheses_close_token_creator(token_creation_data_t data);

/**
** @brief Classed by priority (Needed because command return always a token)
** - Doesn't end by a empty struct but need to use "token_finders_count".
**/
extern const token_finder_t token_finders[];

/**
** @brief The count of token finders inside "token_finders" array.
**/
extern const size_t token_finders_count;

/**
** Use to transform an input to token.
** @param context The shell context.
** @param parser_tokens The parser tokens.
** @return The resulting tokens.
**/
tokens_t *tokenizer(shell_context_t *context, parser_tokens_t *parser_tokens);

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_dump(tokens_t *tokens);

/**
** Use to dump token.
** @param token The token.
**/
void token_dump_single(uint32_t id, token_t token);

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_free(tokens_t *tokens);

/**
** Use to dump token list.
** @param tokens The token list.
**/
void token_free_value(token_t *token);

#endif /* !MYTOKENIZER_H */
