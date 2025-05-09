/*
** EPITECH PROJECT, 2025
** write.c
** File description:
** write
*/

#include "dataframe.h"

static void write_header(dataframe_t *frame, FILE *file)
{
    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        fprintf(file, "%s", frame->column_header[i].name);
        if (i + 1 < frame->nb_columns) {
            fprintf(file, "%s", frame->separator);
        }
    }
    fprintf(file, "\n");
}

static void write_row(dataframe_t *frame, dataframe_row_t *row, FILE *file)
{
    for (uint32_t i = 0; i < row->entry_count; i++) {
        fprintf(file, "%s", row->entries[i].string_value);
        if (i + 1 < row->entry_count) {
            fprintf(file, "%s", frame->separator);
        }
    }
    fprintf(file, "\n");
}

static void write_body(dataframe_t *frame, FILE *file)
{
    dataframe_row_t *row = frame->first_row;

    while (row != NULL) {
        write_row(frame, row, file);
        row = row->next;
    }
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = NULL;

    if (dataframe == NULL || filename == NULL) {
        return 84;
    }
    file = fopen(filename, "w");
    if (file == NULL) {
        return 84;
    }
    write_header(dataframe, file);
    write_body(dataframe, file);
    fclose(file);
    return 0;
}
