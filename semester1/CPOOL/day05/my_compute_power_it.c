/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int stock = 1;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    while (p > 0) {
        stock = stock * nb;
        p = p - 1;
    }
    return (stock);
}
