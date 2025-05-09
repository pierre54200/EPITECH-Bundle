/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_info
*/

#include "dataframe.h"

void df_info(dataframe_t *frame)
{
    if (frame == NULL)
        return;
    printf("%u column%s:\n", frame->nb_columns,
        frame->nb_columns > 1 ? "s" : "");
    for (uint32_t i = 0; i < frame->nb_columns; i++) {
        printf("- %s: %s\n", frame->column_header[i].name,
            type_as_string(frame->column_header[i].type));
    }
}
