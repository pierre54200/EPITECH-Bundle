/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dataframe_destoyer
*/

#include "dataframe.h"

void destroy_entries(dataframe_entry_t *entries, uint32_t entry_count)
{
    if (entries == NULL)
        return;
    for (uint32_t i = 0; i < entry_count; i++) {
        if (entries[i].string_value == NULL)
            continue;
        free(entries[i].string_value);
    }
    free(entries);
}

void destroy_rows(dataframe_t *frame)
{
    dataframe_row_t *row = frame->first_row;
    dataframe_row_t *next_row = NULL;

    while (row != NULL) {
        next_row = row->next;
        destroy_entries(row->entries, row->entry_count);
        free(row);
        row = next_row;
    }
}

static void destroy_header(column_header_t *header, uint32_t column_count)
{
    if (header == NULL) {
        return;
    }
    for (uint32_t i = 0; i < column_count; i++) {
        if (header[i].name == NULL)
            continue;
        free(header[i].name);
    }
    free(header);
}

void df_free(dataframe_t *frame)
{
    if (frame == NULL)
        return;
    if (frame->separator != NULL)
        free(frame->separator);
    destroy_header(frame->column_header, frame->nb_columns);
    destroy_rows(frame);
    free(frame);
}
