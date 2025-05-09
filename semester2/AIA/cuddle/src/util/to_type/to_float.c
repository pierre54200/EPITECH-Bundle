/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** to_float
*/

#include "dataframe.h"

bool to_float(dataframe_entry_t *entry)
{
    if (!is_numerical(entry->string_value)) {
        return false;
    }
    entry->float_value = strtof(entry->string_value, NULL);
    free(entry->string_value);
    entry->string_value = NULL;
    asprintf(&entry->string_value, "%.2f", entry->float_value);
    return entry->string_value != NULL;
}
