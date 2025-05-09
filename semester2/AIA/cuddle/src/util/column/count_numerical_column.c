/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** count_numerical_column
*/

#include "dataframe.h"

uint32_t count_numerical_column(const dataframe_t *frame)
{
    uint32_t count = 0;

    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        if ((frame->column_header[i].type & NUMERICAL) == 0) {
            continue;
        }
        count++;
    }
    return count;
}
