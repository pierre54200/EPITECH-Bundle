/*
** EPITECH PROJECT, 2025
** find_in_string.c
** File description:
** find string in another string
*/
int find_in_string(char *src, char *str)
{
    int j = 0;
    int len = 0;

    for (; str[len] != 0; len++);
    for (int i = 0; src[i] != 0; i++) {
        if (src[i] != str[j])
            j = 0;
        if (src[i] == str[j])
            j++;
        if (str[j] == 0)
            return i - len + 1;
    }
    return -1;
}
