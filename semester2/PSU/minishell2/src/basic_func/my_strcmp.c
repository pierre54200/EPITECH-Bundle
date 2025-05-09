/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** compare the lenght of both strings
*/

int my_strcmp(char *s1, char *s2)
{
    int result = 0;
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    result = s1[i] - s2[i];
    return result;
}
