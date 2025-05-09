/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** row_popper
*/
#include "dataframe.h"

int pop_row(dataframe_t *frame, dataframe_row_t *row)
{
    if (row == NULL || frame == NULL)
        return 84;
    if (frame->first_row == row)
        frame->first_row = row->next;
    if (frame->last_row == row)
        frame->last_row = row->previous;
    if (row->previous != NULL)
        row->previous->next = row->next;
    if (row->next != NULL)
        row->next->previous = row->previous;
    destroy_entries(row->entries, row->entry_count);
    free(row);
    frame->nb_rows--;
    return 0;
}
