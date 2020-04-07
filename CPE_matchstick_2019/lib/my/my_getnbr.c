/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Day04
*/

#include <stdio.h>

void my_put_nbr(int nb);
void my_putchar(char c);

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    for (; str[i] != '\0' && str[i] != '\n'; i += 1)
    {
        n += + str[i] - 48;
        n *= 10;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}
