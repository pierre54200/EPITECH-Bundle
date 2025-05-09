/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** row_pusher
*/

#include "dataframe.h"

int push_row(dataframe_t *frame, dataframe_row_t *new_row)
{
    if (new_row == NULL)
        return 84;
    if (frame->first_row != NULL)
        frame->first_row->previous = new_row;
    new_row->next = frame->first_row;
    frame->first_row = new_row;
    if (frame->last_row == NULL)
        frame->last_row = new_row;
    frame->nb_rows++;
    return 0;
}

int pushback_row(dataframe_t *frame, dataframe_row_t *new_row)
{
    if (new_row == NULL)
        return 84;
    if (frame->last_row != NULL)
        frame->last_row->next = new_row;
    new_row->previous = frame->last_row;
    frame->last_row = new_row;
    if (frame->first_row == NULL)
        frame->first_row = new_row;
    frame->nb_rows++;
    return 0;
}
