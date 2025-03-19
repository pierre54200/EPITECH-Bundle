/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** task07
*/

static int puissance_10(int i)
{
    int result = 1;

    if (i == 0)
        return 1;
    while (i != 0) {
        result = result * 10;
        i = i - 1;
    }
    return (result);
}

int my_put_nbr(int nb)
{
    int i = 0;
    int counter = nb;
    int stock = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        if (nb == 0)
            nb = 2147483648;
        counter = nb;
    }
    for (; counter > 10; i++)
        counter = counter / 10;
    while (i >= 0) {
        stock = nb / puissance_10(i);
        nb = nb - stock * puissance_10(i);
        i = i - 1;
        my_putchar('0' + stock);
    }
}
