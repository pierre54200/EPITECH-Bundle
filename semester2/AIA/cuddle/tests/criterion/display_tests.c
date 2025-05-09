/*
** EPITECH PROJECT, 2025
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"

static char *file = "./tests/criterion/files/basic.csv";

Test(head, head_size_zero)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_head(frame, 0);

    cr_assert_(head != NULL);
    df_free(frame);
    df_free(head);
}

Test(head, head_size_neg)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_head(frame, -1);

    cr_assert_(head == NULL);
    df_free(frame);
}

Test(head, head_size_too_big)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_head(frame, 60);

    cr_assert_(head != NULL);
    df_free(frame);
    df_free(head);
}

Test(head, real_head_size_zero)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_real_head(frame, 0);

    cr_assert_(head != NULL);
    df_free(frame);
    df_free(head);
}

Test(head, real_head_size_neg)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_real_head(frame, -1);

    cr_assert_(head != NULL);
    df_free(frame);
}

Test(head, real_head_size_too_big)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *head = df_real_head(frame, 60);

    cr_assert_(head != NULL);
    df_free(frame);
    df_free(head);
}

Test(reverse, not_null)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *reverse = df_reverse(frame);

    cr_assert_(reverse != NULL);
    df_free(frame);
    df_free(reverse);
}

Test(reverse, null)
{
    dataframe_t *reverse = df_reverse(NULL);

    cr_assert_(reverse == NULL);
}

Test(tail, tail_size_zero)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_tail(frame, 0);

    cr_assert_(tail != NULL);
    df_free(frame);
    df_free(tail);
}

Test(tail, tail_size_neg)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_tail(frame, -1);

    cr_assert_(tail == NULL);
    df_free(frame);
}

Test(tail, tail_size_too_big)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_tail(frame, 60);

    cr_assert_(tail != NULL);
    df_free(frame);
    df_free(tail);
}

Test(tail, real_tail_size_zero)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_real_tail(frame, 0);

    cr_assert_(tail != NULL);
    df_free(frame);
    df_free(tail);
}

Test(tail, real_tail_size_neg)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_real_tail(frame, -1);

    cr_assert_(tail != NULL);
    df_free(frame);
    df_free(tail);
}

Test(tail, real_tail_size_too_big)
{
    dataframe_t *frame = df_read_csv(file, NULL);
    dataframe_t *tail = df_real_tail(frame, 60);

    cr_assert_(tail != NULL);
    df_free(frame);
    df_free(tail);
}
