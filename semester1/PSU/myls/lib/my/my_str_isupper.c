/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** upper
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
    return 1;
}
