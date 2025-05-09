/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** dupe_frame
*/

#include "dataframe.h"

static int add_all_rows(dataframe_t *dest, dataframe_t *src)
{
    dataframe_row_t *rows = src->first_row;
    dataframe_row_t *duped_row = NULL;

    while (rows != NULL) {
        duped_row = dupe_row(rows);
        if (duped_row == NULL) {
            return 84;
        }
        pushback_row(dest, duped_row);
        rows = rows->next;
    }
    return 0;
}

dataframe_t *dupe_frame(dataframe_t *src)
{
    dataframe_t *frame = dupe_header(src);

    if (frame == NULL) {
        return NULL;
    }
    if (add_all_rows(frame, src) != 0) {
        df_free(frame);
        return NULL;
    }
    return frame;
}
