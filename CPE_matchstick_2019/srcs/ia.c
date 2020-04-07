/*
** EPITECH PROJECT, 2020
** ia.c
** File description:
** Thomas Olry's ia.c made the 01/14/2020
*/

#include "matchstick.h"

void max_matching(int max_match, int line, char **map)
{
    update_map(map, line, max_match);
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(max_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void less_matching(int count, int line, char **map)
{
    update_map(map, line, count);
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(count);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int last(int count, int line, int max_match, char **map)
{
    if (LAST_LINE) {
        count = count_match(map[find_line(map)]) - 1;
        line = find_line(map);
    }
    return (count);
}

int basic_ia(char **map, int max_match, int nb_line)
{
    int line = 0;
    int count = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        if (count_match(map[i]) > count) {
            count = count_match(map[i]);
            line = i;
        }
    }
    count = last(count, line, max_match, map);
    if (count > max_match)
        max_matching(max_match, line, map);
    else
        less_matching(count, line, map);
    print_map(map);
    if (check_all_match(map) <= 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}
