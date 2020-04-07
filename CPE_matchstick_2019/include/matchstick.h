/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** Thomas Olry's matchstick.h made the 01/12/2020
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#define LAST_LINE count_line(map) == 1 && count_match(map[find_line(map)]) \
        < max_match && count_match(map[find_line(map)]) != 1

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>

typedef struct matchstick_s {
    int x;
    int nb_line;
    int max_match;
    int i;
    int match;
    int line;
    size_t n;
} matchstick_t;

//main

int is_num(char *);
void print_map(char **);

//set_game

int set_line(int, int, int, char *);
int remove_match(char **, int, int);

//create_game

void print_star(char *, int);
void first_line(char **, int, int);
void last_line(char **, int, int, int);
void last_char(char **, int, int);
char **create_map(int);

//game

int check_all_match(char **);
char **update_map(char **, int, int);
int the_game(char **, matchstick_t *, char *);
void print_remove(int, int);

//error_handling

int line_error(int, int, char *);
int match_error(int, int, char *, char *);
int count_match(char *);

//ia

void max_matching(int, int, char **);
void less_matching(int, int, char **);
int basic_ia(char **, int, int);

//ia2

int find_line(char **);
int count_line(char **);

//lib

int my_getnbr(char *);
int my_putstr(char const *);
int my_strlen(char const *);
void my_put_nbr(int);
void my_putchar(char);

#endif /* !MATCHSTICK_H_ */
