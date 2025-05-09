/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** file_next_line
*/

#include "dataframe.h"

static bool is_comment(char *str, char *comment_prefix)
{
    if (strlen(str) < strlen(comment_prefix))
        return false;
    if (strncmp(str, comment_prefix, strlen(comment_prefix)) == 0)
        return true;
    return false;
}

static bool is_line_empty(char *line, char *comment_prefix)
{
    for (uint32_t i = 0; line[i] != '\0'; i++) {
        if (is_comment(line, comment_prefix))
            return true;
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return false;
    }
    return true;
}

char *file_next_line(bool skip_empty_line, char *comment_prefix, FILE *file)
{
    char *buffer = NULL;
    size_t buffer_size = 0;

    while (getline(&buffer, &buffer_size, file) > 0) {
        if (buffer == NULL)
            return NULL;
        if (!is_line_empty(buffer, comment_prefix) || !skip_empty_line)
            return buffer;
        free(buffer);
        buffer = NULL;
    }
    if (buffer != NULL)
        free(buffer);
    return NULL;
}
