/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** num
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
