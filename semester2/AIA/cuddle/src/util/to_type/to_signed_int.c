/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** to_signed_int
*/

#include "dataframe.h"

bool to_signed_int(dataframe_entry_t *entry)
{
    if (!is_numerical(entry->string_value)) {
        return false;
    }
    entry->int_value = strtol(entry->string_value, NULL, 10);
    free(entry->string_value);
    entry->string_value = NULL;
    asprintf(&entry->string_value, "%i", entry->int_value);
    return entry->string_value != NULL;
}
