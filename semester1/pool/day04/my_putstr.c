/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
int my_putstr(char const *str)
{
    int i;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
