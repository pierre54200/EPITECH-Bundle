/*
** EPITECH PROJECT, 2024
** my_print_revalpha.c
** File description:
** task02
*/

int my_print_revalpha(void)
{
    int letter = 'z';

    while (letter >= 'a') {
        my_putchar(letter);
        letter = letter - 1;
    }
    return (0);
}
