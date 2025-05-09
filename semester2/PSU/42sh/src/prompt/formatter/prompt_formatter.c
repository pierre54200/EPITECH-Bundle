/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** prompt_formatter
*/

#include "prompt.h"
#include "minishell.h"
#include "string_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static prompt_format_t find_formatter(const char *str)
{
    prompt_format_t current;
    char *placeholder = NULL;

    for (int i = 0; i < prompt_formatter_count; i++) {
        current = prompt_formatter[i];
        placeholder = current.placeholder;
        if (strncmp(placeholder, str, strlen(placeholder)) == 0)
            return current;
    }
    return (prompt_format_t) { .placeholder = NULL };
}

static int process_formatting(shell_context_t *context, const char *format)
{
    prompt_format_t formatter = find_formatter(format);
    char *formatted = NULL;

    if (formatter.placeholder != NULL) {
        formatted = formatter.parser(context);
        if (formatted != NULL) {
            printf("%s", formatted);
            free(formatted);
            return strlen(formatter.placeholder) + 1;
        }
    }
    printf("%%");
    return 1;
}

void prompt_show_formatted(shell_context_t *context, char *format)
{
    int to_next = 0;

    while (*format) {
        to_next = strchr(format, '%') - format;
        if (to_next <= 0 || (size_t)to_next > strlen(format))
            to_next = strlen(format);
        printf("%.*s", to_next, format);
        format += to_next;
        if (format == NULL || (*format) == '\0')
            break;
        format += process_formatting(context, format + 1);
    }
}
