/*
** EPITECH PROJECT, 2025
** countword.c
** File description:
** countword
*/

#include "./my.h"

static int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] != 0 || s2[i] != 0; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    if (s1[i] == 0 && s2[i] == 0)
        return 1;
    return 0;
}

static int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return i;
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

static int is_a_char(char c)
{
    if ((c >= 'a' && c <= 'z')
    || (c >= 'A' && c <= 'Z') || c == 47 || c == '-')
        return 1;
    return 0;
}

int countline(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        if ((str[i - 1] == ' ' || str[i - 1] == '\t')
        && is_a_char(str[i]) == 1)
            nb++;
    }
    return nb + 1;
}

char *my_strdup(char *av)
{
    char *dest = malloc(sizeof(char *) * (my_strlen(av) + 1));

    for (int i = 0; av[i] != 0; i++) {
        dest[i] = av[i];
    }
    return dest;
}

char *clear(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        str[i] = 0;
    return str;
}

static int count(char **w, char *c, int j)
{
    int result = 0;

    for (int i = 0; w[i] != 0; i++) {
        if (i < j && my_strcmp(w[i], c) == 1)
            return -1;
        if (my_strcmp(w[i], c) == 1)
            result++;
    }
    return result;
}

static int countingword(int *word, char **word2)
{
    char c;

    for (int i = 0; word2[i] != 0; i++)
        word[i] = count(word2, word2[i], i);
    for (int i = 0; word2[i] != 0; i++) {
        if (word[i] == -1)
            continue;
        my_putstr(word2[i]);
        my_putstr(": ");
        c = word[i] + '0';
        write(1, &c, 1);
        my_putstr("\n");
    }
    return 0;
}

int countword(char *av)
{
    int *word = malloc(sizeof(int *) * (countline(av) + 1));
    char **word2 = malloc(sizeof(char **) * (countline(av) + 1));
    char stock[26];
    int j = 0;
    int nb = 0;

    for (int i = 0; av[i] != 0; i++) {
        if ((av[i - 1] == ' ' || av[i - 1] == '\t') && is_a_char(av[i]) == 1) {
            word2[nb] = my_strdup(stock);
            nb++;
            j = 0;
            clear(stock);
        }
        if (is_a_char(av[i]) == 1) {
            stock[j] = av[i];
            j++;
        }
    }
    word2[nb] = my_strdup(stock);
    return countingword(word, word2);
}
