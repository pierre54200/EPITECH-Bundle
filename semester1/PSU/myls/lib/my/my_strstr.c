/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** find a patern in a string
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int a = 0;

    for (; str[i] != '\0'; i++) {
        if (to_find[a] == str[i])
            a++;
        if (to_find[a] == '\0')
            return &str[i - a + 1];
        if (to_find[a] != str[i + 1])
            a = 0;
    }
    str[0] = '\0';
    return 0;
}
