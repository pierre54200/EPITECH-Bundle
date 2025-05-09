/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** to_type
*/

#include "dataframe.h"

int update_all_row(dataframe_t *frame,
    uint32_t column_index, column_type_t downcast)
{
    dataframe_row_t *rows = frame->first_row;

    frame->column_header[column_index].type = downcast;
    while (rows != NULL) {
        if (change_entry_type(&rows->entries[column_index], downcast) != 0) {
            return 84;
        }
        rows = rows->next;
    }
    return 0;
}

dataframe_t *df_to_type(dataframe_t *src,
    const char *column, column_type_t downcast)
{
    dataframe_t *frame = NULL;
    uint32_t column_index = 0;

    if (src == NULL || column == NULL || downcast < 0 ||
            !find_column_index(src, &column_index, column)) {
        return NULL;
    }
    frame = dupe_frame(src);
    if (frame == NULL) {
        return NULL;
    }
    if (update_all_row(frame, column_index, downcast) != 0) {
        df_free(frame);
        return NULL;
    }
    return frame;
}
