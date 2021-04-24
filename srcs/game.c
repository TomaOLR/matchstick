/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** Thomas Olry's game.c made the 01/14/2020
*/

#include "matchstick.h"

int check_all_match(char **map)
{
    int x = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1)
            if (map[i][j] == '|')
                x += 1;
    }
    return (x);
}

char **update_map(char **map, int line, int match)
{
    int len = my_strlen(map[line]);
    int x = 0;

    for (; x != match; len -= 1) {
        if (map[line][len] == '|') {
            map[line][len] = ' ';
            x += 1;
        }
    }
    return (map);
}

void print_remove(int match, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int go_ia(char **map, int max_match, int nb_line , matchstick_t *match)
{
    if (basic_ia(map, max_match, nb_line) == 1)
        return (1);
    my_putstr("\nYour turn:\nLine: ");
    match->x = 0;
    return (0);
}

int the_game(char **map, matchstick_t *m, char *input)
{
    for (; 1; m->i = 0) {
        if (m->i = getline(&input, &m->n, stdin) < 0)
            return (0);
        if (m->i != -1 && m->x == 0) {
            m->line = my_getnbr(input);
            m->x = set_line(m->line, m->x, m->nb_line, input);
        } else if (m->i != -1 && m->x == 1) {
            m->match = my_getnbr(input);
            if (match_error(m->max_match, m->match, map[m->line], input) != 0) {
                my_putstr("Line: ");
                m->x = 0;
            } else if (remove_match(map, m->line, m->match) == 2)
                return (2);
            else
                if (go_ia(map, m->max_match, m->nb_line, m) == 1)
                    return (1);
        }
    }
    return (0);
}
