/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** puts every letter in uppercase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i] - 32;
    return str;
}
