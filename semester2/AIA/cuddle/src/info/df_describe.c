/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe
*/

#include "dataframe.h"

static void update_value_describe(
    dataframe_describe_t *describe,
    dataframe_entry_t *entries)
{
    float value = fget_entries_numerical_value(entries);
    uint32_t row_count = describe->row_count;

    describe->maximum = fmaxf(describe->maximum, value);
    describe->minimal = fminf(describe->minimal, value);
    describe->mean = (describe->mean * row_count + value) / (row_count + 1);
    describe->standard_deviation += value * value;
    describe->row_count++;
}

static void fill_describe(
    dataframe_describe_t *describe,
    dataframe_t *frame, uint32_t column_index)
{
    dataframe_row_t *rows = frame->first_row;

    describe->column_name = frame->column_header[column_index].name;
    describe->maximum = -0x7FFFFFFF;
    describe->minimal = 0x7FFFFFFF;
    describe->mean = 0.0f;
    describe->standard_deviation = 0.0f;
    describe->row_count = 0;
    while (rows != NULL) {
        update_value_describe(describe, &(rows->entries[column_index]));
        rows = rows->next;
    }
    describe->standard_deviation -=
        (describe->mean * describe->mean) * describe->row_count;
    describe->standard_deviation /= describe->row_count;
    describe->standard_deviation = sqrt(describe->standard_deviation);
}

static void show_describe(
    dataframe_describe_t *describes,
    uint32_t numerical_column)
{
    for (uint32_t i = 0; i < numerical_column; i++) {
        printf("Column: %s\n", describes[i].column_name);
        printf("Count: %u\n", describes[i].row_count);
        printf("Mean: %.2f\n", describes[i].mean);
        printf("Std: %.2f\n", describes[i].standard_deviation);
        printf("Min: %.2f\n", describes[i].minimal);
        printf("Max: %.2f\n", describes[i].maximum);
    }
}

void df_describe(dataframe_t *frame)
{
    dataframe_describe_t *df_describes = NULL;
    uint32_t numerical_column = 0;
    uint32_t index = 0;

    if (frame == NULL)
        return;
    numerical_column = count_numerical_column(frame);
    if (numerical_column == 0)
        return;
    df_describes = alloca(sizeof(dataframe_describe_t) * numerical_column);
    for (uint32_t i = 0; index < frame->nb_columns; i++) {
        for (; index < frame->nb_columns &&
            (frame->column_header[index].type & NUMERICAL) == 0; index++);
        if (index >= frame->nb_columns)
            continue;
        fill_describe(&(df_describes[i]), frame, index);
        index++;
    }
    show_describe(df_describes, numerical_column);
}
