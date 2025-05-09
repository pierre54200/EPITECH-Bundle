/*
** EPITECH PROJECT, 2025
** dupe_header.c
** File description:
** duplicate the header
*/

#include "dataframe.h"

static int init_frame_value(dataframe_t *frame, dataframe_t *src)
{
    frame->first_row = NULL;
    frame->last_row = NULL;
    frame->separator = strdup(src->separator);
    frame->nb_columns = src->nb_columns;
    frame->nb_rows = 0;
    if (frame->separator == NULL)
        return 84;
    return 0;
}

static int setup_header(dataframe_t *frame, dataframe_t *src)
{
    column_header_t *header = frame->column_header;

    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        header[i].name = strdup(src->column_header[i].name);
        if (header[i].name == NULL)
            return 84;
        header[i].type = src->column_header[i].type;
    }
    return 0;
}

dataframe_t *dupe_header(dataframe_t *src)
{
    dataframe_t *frame = NULL;

    if (src == NULL)
        return NULL;
    frame = malloc(sizeof(dataframe_t));
    if (frame == NULL)
        return NULL;
    frame->column_header = malloc(sizeof(column_header_t) * src->nb_columns);
    if (frame->column_header == NULL ||
            init_frame_value(frame, src) != 0 ||
            setup_header(frame, src) != 0) {
        df_free(frame);
        return NULL;
    }
    return frame;
}
