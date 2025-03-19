/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** task01
*/
void my_swap(int *a, int *b)
{
    int stock = 0;

    stock = *a;
    *a = *b;
    *b = stock;
}
