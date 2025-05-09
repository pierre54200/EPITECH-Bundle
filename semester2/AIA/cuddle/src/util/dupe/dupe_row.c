/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dupe_row
*/

#include "dataframe.h"

static int copy_row_value(
    dataframe_row_t *new_row,
    dataframe_row_t *row)
{
    new_row->next = NULL;
    new_row->previous = NULL;
    new_row->entry_count = row->entry_count;
    memcpy(new_row->entries, row->entries,
        sizeof(dataframe_entry_t) * row->entry_count);
    for (uint32_t i = 0; i < row->entry_count; i++) {
        new_row->entries[i].string_value =
            strdup(new_row->entries[i].string_value);
        if (new_row->entries[i].string_value == NULL) {
            destroy_entries(row->entries, row->entry_count);
            return 84;
        }
    }
    return 0;
}

dataframe_row_t *dupe_row(dataframe_row_t *row)
{
    dataframe_row_t *new_row = malloc(sizeof(dataframe_row_t));

    if (new_row == NULL)
        return NULL;
    new_row->entries = malloc(sizeof(dataframe_entry_t) * row->entry_count);
    if (new_row->entries == NULL) {
        free(new_row);
        return NULL;
    }
    if (copy_row_value(new_row, row)) {
        free(row);
        return NULL;
    }
    return new_row;
}
