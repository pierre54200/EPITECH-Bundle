/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt
*/

#include "prompt.h"
#include "string_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void clean_input(char *buffer)
{
    remove_trailing_char(buffer, '\n');
    remove_trailing_char(buffer, ' ');
    remove_trailing_char(buffer, '\t');
}

char *prompt_get_input(bool should_clean, bool should_show_exit_message)
{
    char *buffer = NULL;
    size_t buffer_len = 0;
    size_t char_read = 0;

    char_read = getline(&buffer, &buffer_len, stdin);
    if (char_read == -1UL) {
        if (should_show_exit_message)
            IF_IS_TTY(printf("exit\n"));
        if (buffer != NULL)
            free(buffer);
        return NULL;
    }
    if (should_clean)
        clean_input(buffer);
    return buffer;
}
