/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** find a patern in a string
*/

static char *display(char *str, int i, int a)
{
    int j = 0;

    while (str[i + j - a + 1] != '\0') {
        str[j] = str[i + j - a + 1];
        j = j + 1;
    }
    str[j] = '\0';
    return str;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;

    for (; str[i] != '\0'; i++) {
        if (to_find[a] == str[i])
            a++;
        if (to_find[a] == '\0') {
            display(str, i, a);
            return;
        }
        if (to_find[a] != str[i + 1])
            a = 0;
    }
    str[0] = '\0';
    return str;
}
