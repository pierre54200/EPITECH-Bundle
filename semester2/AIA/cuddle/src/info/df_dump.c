/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_dump
*/

#include "dataframe.h"
#include <math.h>

static void dump_header(dataframe_t *frame, size_t *max_length)
{
    printf("Column Header:\n");
    printf("|");
    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        printf(" %*s[%i] |",
            (int)(max_length == NULL ? 0 : max_length[i] -
                snprintf(NULL, 0, "[%i]", frame->column_header[i].type)),
            frame->column_header[i].name,
            frame->column_header[i].type);
    }
    printf("\n");
}

static void dump_row(dataframe_row_t *row, size_t *max_length)
{
    printf("|");
    for (uint32_t i = 0; i < row->entry_count; i++) {
        printf(" %*s |", (int)(max_length == NULL ? 0 : max_length[i]),
            row->entries[i].string_value);
    }
    printf("\n");
}

static void dump_body(dataframe_t *frame, size_t *max_length)
{
    dataframe_row_t *row = frame->first_row;

    while (row != NULL) {
        dump_row(row, max_length);
        row = row->next;
    }
}

static void find_max_length(dataframe_t *frame, size_t *max_length)
{
    dataframe_row_t *row = NULL;

    if (max_length == NULL) {
        return;
    }
    for (uint32_t column = 0; column < frame->nb_columns; column++) {
        max_length[column] = snprintf(NULL, 0, "%s[%i]",
            frame->column_header[column].name,
            frame->column_header[column].type);
        row = frame->first_row;
        while (row != NULL) {
            max_length[column] = MAX(max_length[column],
                strlen(row->entries[column].string_value));
            row = row->next;
        }
    }
}

void df_dump(dataframe_t *frame)
{
    size_t *max_length = NULL;

    if (frame == NULL)
        return;
    if (frame->nb_columns <= 10)
        max_length = alloca(frame->nb_columns * sizeof(size_t));
    find_max_length(frame, max_length);
    dump_header(frame, max_length);
    dump_body(frame, max_length);
}
