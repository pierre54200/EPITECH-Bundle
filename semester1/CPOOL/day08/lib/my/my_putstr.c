/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** task02
*/
int my_putstr(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
