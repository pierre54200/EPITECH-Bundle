/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** task03 reverse a string
*/

char *my_drevstr(char *str)
{
    int i = 0;
    int stock = 0;
    int stock2 = 0;
    int len = 0;

    while (str[len] != '\0') {
        len = len + 1;
    }
        while (i < len) {
            stock = str[i];
            stock2 = str[len - 1];
            str[len - 1] = stock;
            str[i] = stock2;
            i = i + 1;
            len = len - 1;
        }
    return str;
}
