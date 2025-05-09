/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** mystring
*/

#ifndef STRING_UTILS_H
    #define STRING_UTILS_H

    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>

    #define MY_STRDUPA(s) strcpy(alloca(sizeof(char) * strlen(s) + 1), s)
    #define RALLOCA(s) (alloca(sizeof(char) * (strlen(s) + 1)))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))

char *my_array_to_str(char **warray);
char *remove_trailing_char(char *buffer, char c);
char **add_to_array(char **array, char *value);
void free_str_array(char **array);

#endif /* !STRING_UTILS_H */
