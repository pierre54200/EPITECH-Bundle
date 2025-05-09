/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** row_creator
*/

#include "dataframe.h"

static int setup_new_row(dataframe_t *frame,
    dataframe_row_t *new_row, char *line)
{
    char *token = strsep(&line, frame->separator);

    for (uint32_t i = 0; token != NULL; i++) {
        new_row->entries[i].string_value = strdup(token);
        if (new_row->entries[i].string_value == NULL) {
            destroy_entries(new_row->entries, i);
            return 84;
        }
        token = strsep(&line, frame->separator);
    }
    return 0;
}

dataframe_row_t *create_row(dataframe_t *frame, char *line)
{
    dataframe_row_t *new_row = malloc(sizeof(dataframe_row_t));

    if (new_row == NULL)
        return NULL;
    new_row->entry_count = count_column(line, frame->separator);
    new_row->entries = malloc(
        sizeof(dataframe_entry_t) * new_row->entry_count);
    new_row->next = NULL;
    new_row->previous = NULL;
    if (new_row->entries == NULL || setup_new_row(frame, new_row, line) != 0) {
        free(new_row);
        return NULL;
    }
    return new_row;
}
