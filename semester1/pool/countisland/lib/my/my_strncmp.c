/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** compare ascii value of s1 and s2 until a a len n
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;
    int i = 0;

    for (; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    if (n < i)
        return 0;
    result = s1[i] - s2[i];
    return result;
}
