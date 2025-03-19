/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it
** File description:
** task01
*/
int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0)
        return 1;
    while (nb > 0) {
        result = result * nb;
        nb = nb - 1;
    }
    return (result);
}
