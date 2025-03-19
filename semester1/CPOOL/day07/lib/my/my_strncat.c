/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;

    for (; dest[len] != '\0'; len++);
    for (int i = 0; src[i] != '\0'; i++) {
        if (nb == i)
            return dest;
        dest[len + i] = src[i];
    }
    return dest;
}
