/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** csv_reader
*/

#include "dataframe.h"

static void init_frame_value(dataframe_t *frame)
{
    frame->column_header = NULL;
    frame->first_row = NULL;
    frame->last_row = NULL;
    frame->separator = NULL;
    frame->nb_columns = 0;
    frame->nb_rows = 0;
}

static int load_dataframe(
    dataframe_t *frame, FILE *file,
    const char *separator)
{
    init_frame_value(frame);
    frame->separator = strdup(separator);
    if (frame->separator == NULL)
        return 84;
    if (load_frame_header(frame, file) != 0)
        return 84;
    if (load_frame_body(frame, file) != 0)
        return 84;
    load_column_type(frame);
    return 0;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    dataframe_t *new_frame = NULL;
    FILE *file = NULL;

    if (separator == NULL)
        separator = ",";
    if (filename == NULL || separator[0] == '\0')
        return NULL;
    file = fopen(filename, "r");
    if (file == NULL)
        return NULL;
    new_frame = malloc(sizeof(dataframe_t));
    if (new_frame != NULL &&
            load_dataframe(new_frame, file, separator) != 0) {
        df_free(new_frame);
        new_frame = NULL;
    }
    fclose(file);
    return new_frame;
}
