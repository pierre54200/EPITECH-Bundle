/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_unique_values
*/

#include "dataframe.h"

static uint32_t fill_unique_values(
    dataframe_t *frame,
    void **values, uint32_t column_index)
{
    dataframe_row_t *row = frame->first_row;
    uint32_t index = 0;

    values[0] = NULL;
    for (; index < frame->nb_rows && row != NULL; row = row->next) {
        if (!is_value_unique(values, &row->entries[column_index])) {
            continue;
        }
        values[index] = get_entry_value(&row->entries[column_index]);
        values[index + 1] = NULL;
        index++;
    }
    return index;
}

void **df_get_unique_values(dataframe_t *frame, const char *column)
{
    uint32_t unique_value_count = 0;
    uint32_t column_index = 0;
    void **values = NULL;

    if (frame == NULL || !find_column_index(frame, &column_index, column)) {
        return NULL;
    }
    values = malloc(sizeof(void *) * (frame->nb_rows + 1));
    if (values == NULL) {
        return NULL;
    }
    unique_value_count = fill_unique_values(frame, values, column_index);
    return realloc(values, sizeof(void *) * (unique_value_count + 1));
}
