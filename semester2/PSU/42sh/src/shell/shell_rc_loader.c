/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** shell rc loader
*/

#include "minishell.h"
#include "string_utils.h"

#include <stdio.h>

static void handle_rc_file_content(shell_context_t *context, FILE *rcfile)
{
    char *line = NULL;
    size_t len = 0;
    size_t nread = 0;

    nread = getline(&line, &len, rcfile);
    while (nread != -1UL) {
        remove_trailing_char(line, '\n');
        remove_trailing_char(line, ' ');
        handle_input(context, line);
        free(line);
        line = NULL;
        nread = getline(&line, &len, rcfile);
    }
    free(line);
}

int shell_rc_loader(shell_context_t *context)
{
    FILE *rcfile = fopen(RC_FILE_PATH, "r");

    if (rcfile == NULL) {
        fprintf(stderr, "Failed to open rcfile at '%s'.\n", RC_FILE_PATH);
        return 1;
    }
    handle_rc_file_content(context, rcfile);
    fclose(rcfile);
    return 0;
}
