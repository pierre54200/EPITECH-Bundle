/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** load_column_header
*/

#include "dataframe.h"

static int load_header(dataframe_t *frame, char *header_line)
{
    column_header_t *header = malloc(
        sizeof(column_header_t) * frame->nb_columns);
    char *token = NULL;

    if (header == NULL)
        return 84;
    frame->column_header = header;
    token = strsep(&header_line, frame->separator);
    for (int i = 0; token != NULL; i++) {
        header[i].name = strdup(token);
        if (header[i].name == NULL)
            return 84;
        token = strsep(&header_line, frame->separator);
    }
    return 0;
}

int load_frame_header(dataframe_t *frame, FILE *file)
{
    char *line = file_next_line(true, "#", file);

    if (line == NULL)
        return 84;
    remove_trailing_char(line, '\n');
    frame->nb_columns = count_column(line, frame->separator);
    if (frame->nb_columns <= 0 || load_header(frame, line) != 0)
        return 84;
    free(line);
    return 0;
}
