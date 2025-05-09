/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** globbing
*/

#ifndef GLOBBING_H
    #define GLOBBING_H

    #include <stdbool.h>
    #include <stddef.h>
    #include <alloca.h>

    #include "parser.h"

    #define GALLOC_PATH(d, n) (alloca(strlen(d) + 1 + strlen(n) + 1))
    #define GBUILD_PATH(d, n) globbing_build_path(d, n, GALLOC_PATH(d, n))

    #define DEPTH 4

typedef struct {
    char *key;
    bool (*matching)(char *globbing, char *str);
} globbing_matcher_t;

bool globbing_matcher_any_wildcard(char *globbing, char *string);
bool globbing_matcher_single_wildcard(char *globbing, char *string);
bool globbing_matcher_choices(char *globbing, char *string);
bool globbing_matcher_char(char *globbing, char *str);

extern const globbing_matcher_t globbing_matchers[];
extern const size_t globbing_matcher_count;

/**
** @brief Use to find a globbing matcher for a given globbing
** @param globbing The given globbing
** @return The found globbing matcher or a matcher filled by 0
**/
globbing_matcher_t globbing_find_matcher(char *globbing);

/**
** @brief Use to check if a string match a globbing
** @param globbing The given globbing
** @param string The string to check if it's match
** @return True if the globbing match the string else False.
**/
bool globbing_matcher(char *globbing, char *string);

/**
** @brief Use to find if a list of token contains a globbing.
** @param parser_tokens The token list that will be searched
** @param string_len The amount of token that will be read
** @return True if the string contain a globbing
**/
bool globbing_finder(parser_tokens_t *parser_tokens, size_t string_len);

/**
** @brief Use to fill a array base on a globbing
** @param globbing The given globbing
** @param array_ptr A Pointer to a string array that will have every possible
**   input based on the globbing
** @return True the globbing match to anything
**/
bool globbing_load(char *globbing, char ***array_ptr);

/**
** @brief Use to fill a array base on a globbing
** @param dir_from The directory where to search.
** @param globbing The given globbing
** @param array_ptr A Pointer to a string array that will have every possible
**   input based on the globbing
** @return True the globbing match to anything
**/
bool globbing_dir_load(char *dir_from, char *globbing, char ***);

/**
** @brief Use to isolate a globbing by removing every after the first '/'
** @param globbing The default globbing
** @param buffer The buffer where to write the new globbing
** @return The buffer given
**/
char *globbing_isolate(char *globbing, char *buffer);

/**
** @brief Use to see if you should deep search a globbing by checking
**   if the next '/' chain end by a '\0'
** @param globbing The globbing
** @return True if should deep search
**/
bool globbing_should_deep_search(char *globbing);

/**
** @brief Use to fill a buffer with the next dir.
** @param dir_from The current directory where to search.
** @param target_sub_dir The Target sub dir
** @param buffer The buffer where the new path will be wrote
** @return The buffer
**/
char *globbing_build_path(char *dir_from, char *target, char *buffer);

/**
** @brief Use to jump over the first '/' chain.
** @param path The current path
** @return A pointer to the first char after the '/' chain
**/
char *globbing_skip_dir(char *path);

#endif /* !GLOBBING_H */
