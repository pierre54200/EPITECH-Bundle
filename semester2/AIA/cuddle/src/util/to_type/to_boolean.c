/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** to_boolean
*/

#include "dataframe.h"

static bool update_bool_string(dataframe_entry_t *entry)
{
    free(entry->string_value);
    entry->string_value = NULL;
    asprintf(&entry->string_value, entry->bool_value ? "true" : "false");
    return entry->string_value != NULL;
}

bool to_boolean(dataframe_entry_t *entry)
{
    if (is_numerical(entry->string_value)) {
        entry->bool_value = fget_entries_numerical_value(entry) != 0.0;
        return update_bool_string(entry);
    } else if (is_boolean(entry->string_value)) {
        entry->bool_value = get_boolean(entry->string_value);
        return update_bool_string(entry);
    }
    return false;
}
