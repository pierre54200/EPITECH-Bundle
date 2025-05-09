/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** apply
*/

#include "dataframe.h"

static int apply_on(dataframe_t *src,
    uint32_t column_index, void *(*apply_func)(void *value))
{
    dataframe_row_t *row = src->first_row;
    void *new_value = NULL;

    for (; row != NULL; row = row->next) {
        new_value = apply_func(get_entry_value(&row->entries[column_index]));
        if (row->entries[column_index].type == STRING) {
            row->entries[column_index].string_value = new_value;
            continue;
        }
        if (new_value == NULL)
            return 84;
        if (update_entry(&row->entries[column_index], new_value) != 0) {
            return 84;
        }
    }
    return 0;
}

dataframe_t *df_apply(dataframe_t *src,
    const char *column, void *(*apply_func)(void *value))
{
    dataframe_t *frame = NULL;
    uint32_t column_index = 0;

    if (src == NULL || column == NULL || apply_func == NULL ||
            !find_column_index(src, &column_index, column)) {
        return NULL;
    }
    frame = dupe_frame(src);
    if (frame == NULL) {
        return NULL;
    }
    if (apply_on(frame, column_index, apply_func) != 0) {
        df_free(frame);
        return NULL;
    }
    return frame;
}
