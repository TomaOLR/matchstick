/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** Thomas Olry's create_map.c made the 01/13/2020
*/

#include "matchstick.h"

void print_star(char *map, int line)
{
    int i = 0;

    for (; i != (line * 2) + 1; i += 1)
        map[i] = '*';
    map[i] = '\0';
}

void first_line(char **map, int line, int size)
{
    map[0] = malloc(sizeof(char) * size);
    print_star(map[0], line);
}

void last_line(char **map, int line, int size, int i)
{
    map[i] = malloc(sizeof(char) * size);
    print_star(map[i], line);
    map[i + 1] = NULL;
}

void last_char(char **map, int i, int j)
{
    map[i][j] = '*';
    map[i][j + 1] = '\0';
}

char **create_map(int line)
{
    int size = (line * 2) + 2;
    char **map = malloc(sizeof(char *) * size);
    int space = line - 1;
    int match = 1;
    int i = 1;

    first_line(map, line, size);
    for (int j = 0; i != line + 1; i += 1, space -= 1, match += 2, j = 0) {
        map[i] = malloc(sizeof(char) * (line * 2) + 3);
        map[i][j] = '*';
        j += 1;
        for (; j != space + 1; j += 1)
            map[i][j] = ' ';
        for (int x = 0; x != match; j += 1, x += 1)
            map[i][j] = '|';
        for (int k = 0; k != space; j += 1, k += 1)
            map[i][j] = ' ';
        last_char(map, i, j);
    }
    last_line(map, line, size, i);
    return (map);
}
