/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** load_column_header
*/

#include "dataframe.h"

static bool is_row_valid(dataframe_t *frame, char *line)
{
    if (count_column(line, frame->separator) != frame->nb_columns) {
        return false;
    }
    return true;
}

int load_frame_body(dataframe_t *frame, FILE *file)
{
    char *line = file_next_line(true, "#", file);

    for (; line != NULL; line = file_next_line(true, "#", file)) {
        remove_trailing_char(line, '\n');
        if (!is_row_valid(frame, line))
            return 84;
        pushback_row(frame, create_row(frame, line));
        free(line);
    }
    return 0;
}
