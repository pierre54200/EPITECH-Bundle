/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_filtering
*/

#include "dataframe.h"

static int filter_based_add(
    dataframe_t *frame, dataframe_t *ref_frame,
    uint32_t column_index, bool (*filter_func)(void *value))
{
    dataframe_row_t *rows = ref_frame->first_row;
    dataframe_row_t *duped_row = NULL;

    while (rows != NULL) {
        if (!filter_func(get_entry_value(&rows->entries[column_index]))) {
            rows = rows->next;
            continue;
        }
        duped_row = dupe_row(rows);
        if (duped_row == NULL)
            return 84;
        pushback_row(frame, duped_row);
        rows = rows->next;
    }
    return 0;
}

dataframe_t *df_filter(
    dataframe_t *ref_frame,
    const char *column, bool (*filter_func)(void *value))
{
    dataframe_t *frame = dupe_header(ref_frame);
    uint32_t index = 0;

    if (frame == NULL || filter_func == NULL) {
        return NULL;
    }
    if (!find_column_index(frame, &index, column) ||
            filter_based_add(frame, ref_frame, index, filter_func) != 0) {
        df_free(frame);
        return NULL;
    }
    return frame;
}
