/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_values
*/

#include "dataframe.h"

static void fill_values(
    dataframe_t *frame,
    void **values, uint32_t column_index)
{
    dataframe_row_t *row = frame->first_row;
    uint32_t index = 0;

    for (index = 0; index < frame->nb_rows && row != NULL; index++) {
        values[index] = get_entry_value(&row->entries[column_index]);
        row = row->next;
    }
    values[index] = NULL;
}

void **df_get_values(dataframe_t *frame, const char *column)
{
    uint32_t column_index = 0;
    void **values = NULL;

    if (frame == NULL || !find_column_index(frame, &column_index, column)) {
        return NULL;
    }
    values = malloc(sizeof(void *) * (frame->nb_rows + 1));
    if (values == NULL) {
        return NULL;
    }
    fill_values(frame, values, column_index);
    return values;
}
