/*
** EPITECH PROJECT, 2024
** puissance_double10.c
** File description:
** power 10 of a double
*/

double fpuissancedouble_10(int i)
{
    double result = 1;

    if (i == 0)
        return 1;
    for (; i != 0; i--)
        result = result * 10;
    return (result);
}
