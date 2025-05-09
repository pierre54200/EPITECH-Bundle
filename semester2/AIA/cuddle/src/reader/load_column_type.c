/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** load_column_type
*/

#include "dataframe.h"

static void init_types(uint8_t *types, uint32_t column_count)
{
    for (uint32_t i = 0; i < column_count; i++) {
        types[i] = ALL_TYPE;
    }
}

static void set_types(dataframe_t *frame, uint8_t *types)
{
    dataframe_row_t *row = frame->first_row;

    for (uint32_t i = 0; i < frame->nb_columns; i++)
        frame->column_header[i].type = types[i];
    while (row != NULL) {
        for (uint32_t i = 0; i < row->entry_count; i++)
            update_entry_type(&(row->entries[i]), types[i]);
        row = row->next;
    }
}

static uint8_t find_entry_type(dataframe_entry_t *entry)
{
    uint8_t type = STRING;

    if (is_signed_int(entry->string_value)) {
        type |= INT;
        if (is_unsigned_int(entry->string_value))
            type |= UINT;
    }
    if (is_float(entry->string_value)) {
        type |= FLOAT;
    }
    if (type == STRING && is_boolean(entry->string_value))
        type |= BOOL;
    return type;
}

static void determine_types(dataframe_t *frame, uint8_t *types)
{
    dataframe_row_t *row = frame->first_row;

    while (row != NULL) {
        for (uint32_t i = 0; i < row->entry_count; i++)
            types[i] &= find_entry_type(&(row->entries[i]));
        row = row->next;
    }
}

static void find_right_types(uint8_t *types, uint32_t column_count)
{
    for (uint32_t i = 0; i < column_count; i++) {
        if (types[i] & UINT)
            types[i] = UINT;
        if (types[i] & INT)
            types[i] = INT;
        if (types[i] & FLOAT)
            types[i] = FLOAT;
        if (types[i] & BOOL)
            types[i] = BOOL;
    }
}

void load_column_type(dataframe_t *frame)
{
    uint8_t *types = alloca(frame->nb_columns * sizeof(uint8_t));

    init_types(types, frame->nb_columns);
    determine_types(frame, types);
    find_right_types(types, frame->nb_columns);
    set_types(frame, types);
    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        update_all_row(frame, i, frame->column_header[i].type);
    }
}
