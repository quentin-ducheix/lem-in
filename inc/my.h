/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct door_s {
	char *name;
	struct door_s *next;
} door_t;

typedef struct node_s {
	int value;
	char *label;
	door_t *door;
	struct node_s *next;
	struct node_s *prev;
} node_t;

typedef struct carte_s {
	int tempo;
	int ants;
	int rooms;
	int track;
	int tp;
	int cmd;
	node_t *begin;
	node_t *ending;
	node_t *start;
	node_t *finish;
} carte_t;

int get_ants(carte_t *carte, char **arr);
int get_door(carte_t *carte, char **arr);
int get_node(carte_t *carte, char **arr);
void ini_carte (carte_t *carte);
void getcmd(carte_t *carte, int val);
int for_door(char **arr, carte_t *carte, int i);
int plus_node(carte_t *carte, char **arr);
int parserdt2(carte_t *carte, char *str);
int parserdt(carte_t *carte, char *str);
int parsertp(carte_t *carte, char *str);
int parser(carte_t *carte);
int be_node(node_t *node, char *str);
int be_door(char **arr, carte_t *carte, int i);
int be_name_node(char **arr);

char **conv_array(char *s, char var);
int my_get_nbr (char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char *str);
char is_num(char *str);
int my_str_isnum(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char *str);
char *my_strdup(char *src);

#endif
