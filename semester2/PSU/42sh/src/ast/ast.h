/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast
*/

#ifndef AST_H
    #define AST_H

    #include "token.h"
    #include "minishell.h"
    #include "my_common.h"

    #include <stdlib.h>
    #include <stdbool.h>

    #define NODE_TOKEN(n) ((n)->node.token->token)
    #define NODE_TYPE(n) (NODE_TOKEN(n).token_type)

typedef struct ast_context {
    shell_context_t *shell_context;
} ast_context_t;

typedef struct ast_node {
    tokens_t *token;
} ast_node_t;

typedef struct ast {
    ast_context_t *context;
    ast_node_t node;
    struct ast *right;
    struct ast *left;
} ast_t;

/************************/
/* EXECUTOR | VALIDATOR */
/************************/

typedef bool (*ast_resolver_func_t)(ast_t *self);

// IO
bool ast_write_resolver(ast_t *self);
bool ast_append_resolver(ast_t *self);
bool ast_send_file_resolver(ast_t *self);
bool ast_send_stdin_resolver(ast_t *self);
// LINKER
bool ast_or_resolver(ast_t *self);
bool ast_pipe_resolver(ast_t *self);
bool ast_and_resolver(ast_t *self);
// LITERAL
bool ast_literal_resolver(ast_t *self);
// SEPARATOR
bool ast_fork_resolver(ast_t *self);
bool ast_separator_resolver(ast_t *self);
// PARENTHESES
bool ast_parentheses_resolver(ast_t *self);

/* -- EXECUTOR -- */

typedef exitcode_t (*ast_executor_func_t)(ast_t *self);

typedef struct {
    ast_resolver_func_t resolver;
    ast_executor_func_t execute;
} ast_executor_t;

extern const ast_executor_t ast_executor[];
extern const size_t ast_executor_count;

// IO
exitcode_t ast_write_executor(ast_t *self);
exitcode_t ast_append_executor(ast_t *self);
exitcode_t ast_send_file_executor(ast_t *self);
exitcode_t ast_send_stdin_executor(ast_t *self);
// LINKER
exitcode_t ast_or_executor(ast_t *self);
exitcode_t ast_and_executor(ast_t *self);
exitcode_t ast_pipe_executor(ast_t *self);
// LITERAL
exitcode_t ast_literal_executor(ast_t *self);
// SEPARATOR
exitcode_t ast_separator_executor(ast_t *self);
exitcode_t ast_fork_executor(ast_t *self);
// PARENTHESE
exitcode_t ast_parentheses_executor(ast_t *self);

/* -- VALIDATOR -- */

typedef bool (*ast_validator_func_t)(ast_t *self);

typedef struct {
    ast_resolver_func_t resolver;
    ast_validator_func_t validate;
} ast_validator_t;

extern const ast_validator_t ast_validator[];
extern const size_t ast_validator_count;

// IO
bool ast_write_validator(ast_t *self);
bool ast_append_validator(ast_t *self);
bool ast_send_file_validator(ast_t *self);
bool ast_send_stdin_validator(ast_t *self);
// LINKER
bool ast_or_validator(ast_t *self);
bool ast_and_validator(ast_t *self);
bool ast_pipe_validator(ast_t *self);
// LITERAL
bool ast_literal_validator(ast_t *self);
// SEPARATOR
bool ast_fork_validator(ast_t *self);
bool ast_separator_validator(ast_t *self);
// PARENTHESES
bool ast_parentheses_validator(ast_t *self);

/***********/
/* BUILDER */
/***********/

typedef struct ast_builder {
    token_type_t type;
    ast_t *(*builder)(ast_t **stage, tokens_t *token, ast_context_t *context);
} ast_builder_t;

extern const ast_builder_t ast_builders[];
extern const size_t ast_builders_count;

ast_t *build_separator_node(ast_t **stage,
    tokens_t *token, ast_context_t *context);
ast_t *build_linker_node(ast_t **root,
    tokens_t *token, ast_context_t *context);
ast_t *build_literal_node(ast_t **stage,
    tokens_t *token, ast_context_t *context);
ast_t *build_io_node(ast_t **root,
    tokens_t *token, ast_context_t *context);
ast_t *build_parenthese_node(ast_t **root,
    tokens_t *token, ast_context_t *context);

ast_t *ast_build(shell_context_t *shell, tokens_t *tokens);
void ast_free(ast_t *ast, ast_context_t *context);

ast_t **find_current_stage(ast_t **root);

exitcode_t ast_exec(ast_t *ast);
bool ast_validate(ast_t *ast);
void ast_dump(ast_t *ast);

#endif /* !AST_H */
