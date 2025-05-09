/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** task03
*/
int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return i;
}

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != 0; i++);
    return i;
}
