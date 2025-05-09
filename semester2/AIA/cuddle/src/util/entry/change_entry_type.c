/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** change_entry_type
*/

#include "dataframe.h"

static bool numerical_entry_change(
    dataframe_entry_t *entry, column_type_t type)
{
    bool valid = false;

    if (!is_numerical(entry->string_value))
        return false;
    if (type == UINT)
        valid = to_unsigned_int(entry);
    if (type == INT)
        valid = to_signed_int(entry);
    if (type == FLOAT)
        valid = to_float(entry);
    return valid;
}

int change_entry_type(dataframe_entry_t *entry, column_type_t type)
{
    bool valid = type == STRING;

    if (entry == NULL) {
        return 84;
    }
    if ((type & NUMERICAL) != 0) {
        valid = numerical_entry_change(entry, type);
    } else if (type == BOOL && (is_boolean(entry->string_value) ||
            is_numerical(entry->string_value))) {
        valid = to_boolean(entry);
    }
    if (valid)
        entry->type = type;
    return valid ? 0 : 84;
}
