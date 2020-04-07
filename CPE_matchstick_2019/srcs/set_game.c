/*
** EPITECH PROJECT, 2020
** set_game.c
** File description:
** Thomas Olry's set_game.c made the 01/15/2020
*/

#include "matchstick.h"

int set_line(int line, int x, int nb_line, char *input)
{
    if (line_error(nb_line, line, input) != 0) {
        my_putstr("Line: ");
        x = 0;
    } else {
        my_putstr("Matches: ");
        x = 1;
    }
    return (x);
}

int remove_match(char **map, int line, int match)
{
    update_map(map, line, match);
    print_remove(match, line);
    print_map(map);
    if (check_all_match(map) <= 0) {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    return (0);
}
