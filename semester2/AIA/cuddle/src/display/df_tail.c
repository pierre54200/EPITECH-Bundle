/*
** EPITECH PROJECT, 2025
** df_tail.c
** File description:
** tail
*/

#include "dataframe.h"

dataframe_t *df_real_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *data = NULL;
    dataframe_row_t *row;
    dataframe_row_t *new_row = NULL;
    int i = 0;

    if (dataframe == NULL)
        return NULL;
    row = dataframe->last_row;
    if (nb_rows < 0)
        nb_rows = dataframe->nb_rows + nb_rows;
    data = dupe_header(dataframe);
    for (; dataframe->last_row != NULL && i < nb_rows; i++) {
        new_row = dupe_row(dataframe->last_row);
        push_row(data, new_row);
        dataframe->last_row = dataframe->last_row->previous;
    }
    data->nb_rows = i;
    dataframe->last_row = row;
    data->last_row = data->first_row;
    return data;
}

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *data = NULL;
    dataframe_row_t *row;
    dataframe_row_t *new_row = NULL;
    int i = 0;

    if (dataframe == NULL || nb_rows < 0)
        return NULL;
    row = dataframe->last_row;
    data = dupe_header(dataframe);
    for (; dataframe->last_row != NULL && i < nb_rows; i++) {
        new_row = dupe_row(dataframe->last_row);
        push_row(data, new_row);
        dataframe->last_row = dataframe->last_row->previous;
    }
    data->nb_rows = i;
    dataframe->last_row = row;
    data->last_row = data->first_row;
    return data;
}
