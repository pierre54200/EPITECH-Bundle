/*
** EPITECH PROJECT, 2024
** diplay
** File description:
** diplay space and the point of the star
*/

void space(int spacing)
{
    for (; spacing > 0; spacing--)
        my_putchar(' ');
}

void point(int pointing)
{
    for (; pointing > 0; pointing--)
        my_putchar('*');
}

void enter(void)
{
    my_putchar('\n');
}
