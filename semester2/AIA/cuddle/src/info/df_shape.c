/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_shape
*/

#include "dataframe.h"

dataframe_shape_t df_shape(dataframe_t *frame)
{
    dataframe_shape_t shape = { 0 };

    if (frame == NULL)
        return shape;
    shape.nb_columns = frame->nb_columns;
    shape.nb_rows = frame->nb_rows;
    return shape;
}
