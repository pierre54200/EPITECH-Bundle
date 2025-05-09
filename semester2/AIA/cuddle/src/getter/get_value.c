/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_value
*/

#include "dataframe.h"

void *df_get_value(
    dataframe_t *frame, int rindex,
    const char *column)
{
    dataframe_row_t *row = NULL;
    uint32_t row_index = rindex;
    uint32_t column_index = 0;

    if (frame == NULL || rindex < 0 || frame->nb_rows < row_index ||
            !find_column_index(frame, &column_index, column)) {
        return NULL;
    }
    row = frame->first_row;
    for (uint32_t current_row = 0; current_row < row_index; current_row++)
        row = row->next;
    return get_entry_value(&row->entries[column_index]);
}
