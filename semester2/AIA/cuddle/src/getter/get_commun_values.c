/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_unique_values
*/

#include "dataframe.h"

static void **fill_commun_values(
    dataframe_t *frame, uint32_t column_index,
    uint32_t target_column_index, void *target_column_value)
{
    dataframe_row_t *row = frame->first_row;
    uint32_t index = 0;
    void **values = NULL;

    values = malloc(sizeof(void *) * (frame->nb_rows + 1));
    if (values == NULL)
        return NULL;
    values[0] = NULL;
    for (; index < frame->nb_rows && row != NULL; row = row->next) {
        if (!is_entry_equals(target_column_value,
                &row->entries[target_column_index])) {
            continue;
        }
        values[index] = get_entry_value(&row->entries[column_index]);
        values[index + 1] = NULL;
        index++;
    }
    return realloc(values, sizeof(void *) * (index + 1));
}

void **df_get_common_values(dataframe_t *frame,
    const char *column, const char *target_column_name,
    void *target_column_value)
{
    uint32_t column_index = 0;
    uint32_t target_column_index = 0;

    if (frame == NULL || !find_column_index(frame, &column_index, column) ||
        !find_column_index(frame, &target_column_index, target_column_name)) {
        return NULL;
    }
    return fill_commun_values(frame, column_index,
        target_column_index, target_column_value);
}
