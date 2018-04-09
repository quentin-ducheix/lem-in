/*
** EPITECH PROJECT, 2018
** algo.h
** File description:
** algo.h
*/

#ifndef ALGO_H
#define ALGO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

typedef struct course_s {
	char **route;
	int size;
	struct course_s *next;
	struct course_s *prev;
	door_t *door;
	struct course_s *course1;
} course_t;

typedef struct ant_s {
	int tag;
	int node;
	course_t *course;
	struct ant_s *next;
	struct ant_s *prev;
	struct ant_s *start;
	struct ant_s *finish;
	int ants;
} ant_t;

void move_next_node(carte_t *, ant_t *, int *);
void puting_ants(carte_t *, ant_t *);
void epicentre(carte_t *, course_t *);
void sum_ant(ant_t *, int, course_t *);
void rm_ant(ant_t **, ant_t *);
void rst_carte(carte_t *);
void search_node(carte_t *, char *, node_t **);
void go_nodes(carte_t *, node_t *, course_t *);
int search_courses(carte_t *, course_t **);
void for_route(course_t *, course_t *);

#endif
