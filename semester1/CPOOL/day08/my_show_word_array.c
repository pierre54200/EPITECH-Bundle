/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** task03
*/
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    int len = 0;
    int j = 0;
    char *str;

    for (; tab[j] != 0; j++)
        len = len + my_strlen(tab[j]);
    str = malloc(sizeof(char) * (len + j + 1));
    for (int i = 0; i != len + j + 1; i++)
        str[i] = '\0';
    for (int i = 0; tab[i] != 0; i++) {
        my_strcat(str, tab[i]);
        my_strcat(str, "\n");
    }
    my_strcat(str, "\0");
    my_putstr(str);
    return 0;
}
