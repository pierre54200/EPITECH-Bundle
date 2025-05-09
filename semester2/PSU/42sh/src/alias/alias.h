/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** alias
*/

#ifndef ALIAS_H
    #define ALIAS_H

    #include "parser.h"
    #include "minishell.h"

typedef struct alias {
    char *key;
    char *replacement;
    bool usable;
} alias_t;

typedef struct aliases {
    alias_t alias;
    struct aliases *next;
} aliases_t;

typedef enum alias_add_result {
    ALIAS_ADD_FAILED,
    ALIAS_ADD_OVERRIDE,
    ALIAS_ADD_NEW
} alias_add_result_t;

typedef enum alias_remove_result {
    ALIAS_REMOVE_SUCCESS,
    ALIAS_REMOVE_NOTHING
} alias_remove_result_t;

/**
** @brief Add a new aliases to the context aliases.
**    Clone the key and replacement.
** @param context The context where to add the new alias
** @param key The key of the new alias
** @param replacement The replacement of the new alias
** @return The result of the function (See alias#alias_add_result_t)
**/
alias_add_result_t alias_add(shell_context_t *context,
    const char *key, const char *replacement);

/**
** @brief Add a new aliases to the context aliases.
** @param context The context where to add the new aliases
** @param key The key of the new alias
** @param replacement The replacement of the new alias
** @return The result of the function (See alias#alias_add_result_t)
**/
alias_add_result_t alias_add_raw(shell_context_t *context,
    char *key, char *replacement);

/**
** @brief Remove an alias for the aliases of the given context
** @param context The context where to remove the target alias
** @param key The key of the alias
** @return The result of the function (See alias#alias_remove_result_t)
**/
alias_remove_result_t alias_remove(shell_context_t *context, const char *key);

/**
** @brief Use to destroy a unique alias
** @param alias The target alias
** @return Return the next of the given alias
**/
aliases_t *alias_destroy_unique(aliases_t *alias);

/**
** @brief Use to free all given aliases.
** @param aliases The target aliases
**/
void alias_destroy(aliases_t *aliases);

/**
** @brief Use to dump a single given aliases
** @param alias The target alias
**/
void alias_single_dumper(alias_t *alias);

/**
** @brief Use to dump all given aliases
** @param aliases The target aliases
**/
void alias_dump(aliases_t *aliases);

/**
** @brief Find an alias in the aliases list using a string key
** @param context The context of aliases
** @param key The given key
** @return Return the found aliases data or NULL
**/
alias_t *alias_string_find(shell_context_t *context, char *key);

/**
** @brief Find an alias in the aliases list using a tokens list key
** @param context The context of aliases
** @param tokens The given token list
** @return Return the found aliases data or NULL
**/
alias_t *alias_parser_find(shell_context_t *context, parser_tokens_t *tokens);

/**
** @brief Use to reset all alias to a given state
** @param aliases The target aliases
**/
void alias_reset_usage_state(aliases_t *aliases, bool state);

/**
** @brief Use to know if a char is a valid char
** @param c The char
** @return True if the char is a valid alias char
**/
bool alias_is_valid_char(char c);

#endif /* !ALIAS_H_ */
