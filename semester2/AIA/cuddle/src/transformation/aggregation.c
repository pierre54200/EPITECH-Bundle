/*
** EPITECH PROJECT, 2025
** aggregation.c
** File description:
** aggregation
*/

#include "dataframe.h"

static bool validate_column(dataframe_t *frame,
    const char *col, const char **target)
{
    uint32_t column_index = 0;

    if (!find_column_index(frame, &column_index, col))
        return false;
    for (uint32_t i = 0; target[i]; i++) {
        if (!find_column_index(frame, &column_index, target[i]))
            return false;
    }
    return true;
}

dataframe_t *df_groupby(dataframe_t *frame, const char *col,
    const char **target, void *(*agg_func)(void **values, int nb_values))
{
    void **unique_values = NULL;
    void **common_values = NULL;
    void *new_value = NULL;

    if (frame == NULL || col == NULL || target == NULL || agg_func == NULL ||
            !validate_column(frame, col, target))
        return NULL;
    unique_values = df_get_unique_values(frame, col);
    for (uint32_t i = 0; unique_values[i] != NULL; i++) {
        for (uint32_t j = 0; target[j]; j++) {
            common_values = df_get_common_values(frame, col,
                target[j], unique_values[i]);
            new_value = agg_func(common_values, voidtablen(common_values));
            free(new_value);
        }
    }
    free(unique_values);
    return frame;
}
