/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** find_column_index
*/

#include "dataframe.h"

bool find_column_index(
    dataframe_t *frame, uint32_t *column_index,
    const char *column_name)
{
    if (frame == NULL || column_index == NULL || column_name == NULL) {
        return false;
    }
    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        if (strcmp(frame->column_header[i].name, column_name) != 0) {
            continue;
        }
        (*column_index) = i;
        return true;
    }
    return false;
}
