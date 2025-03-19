/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** task04
*/
#include <stdlib.h>

static int count_word(char const *str)
{
    int word = 1;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9' && str[i] < 'A'
            || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
            word++;
    }
    return word;
}

static char **write_string(char const *str, char **tab, int word)
{
    int j = 0;
    int k = 0;

    for (int i = 0; k != word; i++) {
        tab[k][j] = str[i];
        if (str[i] < '0' || str[i] > '9' && str[i] < 'A'
            || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
            k = k + 1;
            j = 0;
        } else {
            j++;
        }
    if ((str[i] < '0' || str[i] > '9' && str[i] < 'A'
        || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
        && (str[i + 1] < '0' || str[i + 1] > '9' && str[i + 1] < 'A'
            || str[i + 1] > 'Z' && str[i + 1] < 'a' || str[i + 1] > 'z')) {
            i++;
    }
    }
    return tab;
}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int word = 0;

    word = count_word(str);
    tab = malloc(sizeof(char *) * (word + 1));
    for (int i = 0; i != word; i++) {
        tab[i] = malloc(sizeof(char) * (10 + 1));
    }
    tab = write_string(str, tab, word);
    for (int i = 0; i != word; i++) {
        if (str[i] < '0' || str[i] > '9' && str[i] < 'A'
        || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
            tab[i + 1] = 0;
    }
    return tab;
}
