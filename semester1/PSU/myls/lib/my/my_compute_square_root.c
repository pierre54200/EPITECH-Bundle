/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** task05
*/
int my_compute_square_root(int nb)
{
    int sqrt = 0;

    for (; sqrt * sqrt < nb; sqrt++);
    if (sqrt * sqrt == nb)
        return sqrt;
    else
        return 0;
}
