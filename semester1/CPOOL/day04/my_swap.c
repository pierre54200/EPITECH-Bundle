/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** task01
*/
void my_swap(int *a, int *b)
{
    int stock_a;
    int stock_b;

    stock_a = *a;
    stock_b = *b;
    *a = stock_b;
    *b = stock_a;
}
