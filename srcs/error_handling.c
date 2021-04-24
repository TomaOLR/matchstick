/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** Thomas Olry's error_handling.c made the 01/15/2020
*/

#include "matchstick.h"

int count_match(char *map)
{
    int x = 0;

    for (int i = 0; map[i] != '\0'; i += 1) {
        if (map[i] == '|')
            x += 1;
    }
    return (x);
}

int line_error(int line, int line_get, char *input)
{
    if (is_num(input) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (line_get > line || line_get == 0) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (0);
}

int match_error(int match, int match_get, char *line, char *input)
{
    if (is_num(input) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (1);
    }
    if (match_get > match) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(match);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (match_get <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (count_match(line) < match_get && match_get <= match) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}
