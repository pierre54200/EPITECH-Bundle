/*
** EPITECH PROJECT, 2025
** df_reverse.c
** File description:
** reverse a dataframe
*/

#include "dataframe.h"

dataframe_t *df_reverse(dataframe_t *dataframe)
{
    dataframe_t *data = NULL;
    dataframe_row_t *row;
    dataframe_row_t *new_row = NULL;

    if (dataframe == NULL)
        return NULL;
    row = dataframe->first_row;
    data = dupe_header(dataframe);
    while (dataframe->first_row != NULL) {
        new_row = dupe_row(dataframe->first_row);
        push_row(data, new_row);
        dataframe->first_row = dataframe->first_row->next;
    }
    data->nb_rows = dataframe->nb_rows;
    dataframe->first_row = row;
    data->last_row = data->first_row;
    return data;
}
