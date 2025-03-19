/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** task02
*/

char *my_strcat(char *dest, char const *src)
{
    int len = 0;

    for (; dest[len] != '\0'; len++);
    for (int i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    return dest;
}
