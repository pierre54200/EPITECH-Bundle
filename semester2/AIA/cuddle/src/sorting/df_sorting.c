/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_sorting
*/
#include "dataframe.h"

static dataframe_row_t *split(dataframe_row_t *head)
{
    dataframe_row_t *fast = head;
    dataframe_row_t *slow = head;
    dataframe_row_t *middle = NULL;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    middle = slow->next;
    slow->next = NULL;
    return middle;
}

static dataframe_row_t *merge(
    uint32_t column_index,
    dataframe_row_t *left, dataframe_row_t *right,
    bool (*sort_func)(void *, void *))
{
    if (left == NULL || right == NULL)
        return (left == NULL ? right : left);
    if (sort_func(get_entry_value(&left->entries[column_index]),
            get_entry_value(&right->entries[column_index]))) {
        left->next = merge(column_index, left->next, right, sort_func);
        if (left->next) {
            left->next->previous = left;
        }
        left->previous = NULL;
        return left;
    }
    right->next = merge(column_index, left, right->next, sort_func);
    if (right->next) {
        right->next->previous = right;
    }
    right->previous = NULL;
    return right;
}

static dataframe_row_t *merge_sort_rows(
    uint32_t column_index,
    dataframe_row_t *head, bool (*sort_func)(void *, void *))
{
    dataframe_row_t *middle = NULL;
    dataframe_row_t *left = NULL;
    dataframe_row_t *right = NULL;

    if (head == NULL || head->next == NULL)
        return head;
    middle = split(head);
    left = merge_sort_rows(column_index, head, sort_func);
    right = merge_sort_rows(column_index, middle, sort_func);
    return merge(column_index, left, right, sort_func);
}

static void sort_frame(dataframe_t *frame,
    uint32_t index, bool (*sort_func)(void *, void *))
{
    dataframe_row_t *current = NULL;

    if (frame == NULL || frame->first_row == NULL ||
            index >= frame->nb_columns) {
        return;
    }
    frame->first_row = merge_sort_rows(index, frame->first_row, sort_func);
    current = frame->first_row;
    while (current->next != NULL) {
        current = current->next;
    }
    frame->last_row = current;
}

dataframe_t *df_sort(
    dataframe_t *src, const char *column,
    bool (*sort_func)(void *value1, void *value2))
{
    dataframe_t *frame = dupe_frame(src);
    dataframe_t *frame_bis = NULL;
    uint32_t column_index = 0;

    if (src == NULL || frame == NULL || sort_func == NULL ||
            !find_column_index(frame, &column_index, column)) {
        df_free(frame);
        return NULL;
    }
    sort_frame(frame, column_index, sort_func);
    frame_bis = df_reverse(frame);
    df_free(frame);
    return frame_bis;
}
