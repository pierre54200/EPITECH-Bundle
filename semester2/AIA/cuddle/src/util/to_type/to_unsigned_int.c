/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** to_unsigned_int
*/

#include "dataframe.h"

bool to_unsigned_int(dataframe_entry_t *entry)
{
    if (!is_numerical(entry->string_value)) {
        return false;
    }
    if (strtol(entry->string_value, NULL, 10) < 0) {
        return false;
    }
    entry->uint_value = strtoul(entry->string_value, NULL, 10);
    free(entry->string_value);
    entry->string_value = NULL;
    asprintf(&entry->string_value, "%d", entry->uint_value);
    return entry->string_value != NULL;
}
