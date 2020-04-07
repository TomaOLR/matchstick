/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Thomas Olry's main.c made the 01/12/2020
*/

#include "matchstick.h"

int is_num(char *arg)
{
    for (int i = 0; arg[i] != '\0' && arg[i] != '\n'; i += 1) {
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return (84);
    }
    return (0);
}

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i += 1) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int main(int ac, char **av)
{
    char **map = NULL;
    char *input = NULL;
    int max_match = 0;
    matchstick_t *match = malloc(sizeof(matchstick_t));

    match->i = 0;
    match->x = 0;

    if (ac != 3)
        return (84);
    if (is_num(av[1]) == 84 || is_num(av[2]) == 84)
        return (84);
    map = create_map(my_getnbr(av[1]));
    match->max_match = my_getnbr(av[2]);
    match->nb_line = my_getnbr(av[1]);

    print_map(map);
    my_putstr("\nYour turn:\nLine: ");
    return (the_game(map, match, input));
}
