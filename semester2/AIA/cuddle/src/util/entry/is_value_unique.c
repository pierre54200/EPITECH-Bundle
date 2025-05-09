/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** count_unique_values
*/

#include "dataframe.h"

bool is_value_unique(void **values, dataframe_entry_t *entry)
{
    for (uint32_t i = 0; values[i] != NULL; i++) {
        if (is_entry_equals(values[i], entry))
            return false;
    }
    return true;
}
