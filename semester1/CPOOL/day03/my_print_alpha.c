/*
** EPITECH PROJECT, 2024
** my_print_alpha.c
** File description:
** task01
*/

int my_print_alpha(void)
{
    int letter = 'a';

    while (letter <= 'z') {
        my_putchar(letter);
        letter = letter + 1;
    }
    return (0);
}
