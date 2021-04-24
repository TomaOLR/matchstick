/*
** EPITECH PROJECT, 2020
** ia2.c
** File description:
** Thomas Olry's ia2.c made the 01/23/2020
*/

#include "matchstick.h"

int count_line(char **map)
{
    int count = 0;
    int i = 0;
    int j = 0;

    for (; map[i] != NULL; i += 1, j = 0) {
        for (; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|') {
                count += 1;
                i += 1;
                j = 0;
            }
    }
    return (count);
}

int find_line(char **map)
{
    int i = 0;
    int j = 0;

    for (; map[i] != NULL; i += 1, j = 0) {
        for (; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|') {
                return (i);
            }
    }
    return (i);
}
