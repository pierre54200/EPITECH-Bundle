/*
** EPITECH PROJECT, 2025
** df_head.c
** File description:
** head
*/

#include "dataframe.h"

dataframe_t *df_real_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *data = NULL;
    dataframe_row_t *row;
    dataframe_row_t *new_row = NULL;
    int i = 0;

    if (dataframe == NULL)
        return NULL;
    row = dataframe->first_row;
    if (nb_rows < 0)
        nb_rows = dataframe->nb_rows + nb_rows;
    data = dupe_header(dataframe);
    for (; dataframe->first_row != NULL && i < nb_rows; i++) {
        new_row = dupe_row(dataframe->first_row);
        pushback_row(data, new_row);
        dataframe->first_row = dataframe->first_row->next;
    }
    data->nb_rows = i;
    dataframe->first_row = row;
    data->last_row = data->first_row;
    return data;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    dataframe_t *data = NULL;
    dataframe_row_t *row;
    dataframe_row_t *new_row = NULL;
    int i = 0;

    if (dataframe == NULL || nb_rows < 0)
        return NULL;
    row = dataframe->first_row;
    data = dupe_header(dataframe);
    for (; dataframe->first_row != NULL && i < nb_rows; i++) {
        new_row = dupe_row(dataframe->first_row);
        pushback_row(data, new_row);
        dataframe->first_row = dataframe->first_row->next;
    }
    data->nb_rows = i;
    dataframe->first_row = row;
    data->last_row = data->first_row;
    return data;
}
