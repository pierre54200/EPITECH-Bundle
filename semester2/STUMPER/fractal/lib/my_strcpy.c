/*
** EPITECH PROJECT, 2025
** my_strcpy
** File description:
** copy str
*/

char *my_strcpy(char *dst, const char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    return dst;
}
