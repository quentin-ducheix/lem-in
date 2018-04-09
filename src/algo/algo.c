/*
** EPITECH PROJECT, 2017
** algo
** File description:
** algo
*/

#include "algo.h"

void rst_carte(carte_t *carte)
{
	for (node_t *tempo = carte->start; tempo; tempo = tempo->next)
		tempo->value = 0;
	carte->begin->value = carte->ants;
}

void search_node(carte_t *carte, char *node_name, node_t **change)
{
	for (node_t *tempo = carte->start; tempo; tempo = tempo->next)
		if (my_strcmp(node_name, tempo->label) == 0) {
			*change = tempo;
			return ;
		}
	*change = NULL;
}

void go_nodes(carte_t *carte, node_t *actu, course_t *route)
{
	node_t *door = NULL;
	course_t *latest = malloc(sizeof(course_t));
	door_t *tempo = malloc(sizeof(door_t));
	door_t *tempo2 = route->door;
	int i = 0;

	if (actu == carte->ending) {
		latest->route = malloc((carte->tempo + 1) * sizeof(char *));
		latest->size = carte->tempo;
		for (; tempo2; i++, tempo2 = tempo2->next)
			latest->route[i] = tempo2->name;
		latest->route[i] = NULL;
		for_route(route, latest);
	}
	for (door_t *temp = actu->door; temp != NULL &&
	actu != carte->ending; temp = temp->next) {
		search_node(carte, temp->name, &door);
		if (door->value == -3 || door->value > carte->tempo) {
			door->value = carte->tempo;
			tempo->name = temp->name;
			tempo->next = route->door;
			route->door = tempo;
			carte->tempo++;
			go_nodes(carte, door, route);
			carte->tempo--;
			(route->door != NULL) ? (route->door = route->door
			->next) : (route->door = NULL);
		}
	}
}

int search_courses(carte_t *carte, course_t **course)
{
	door_t *latest = malloc(sizeof(door_t));

	(*course)->door = NULL;
	(*course)->course1 = NULL;
	latest->name = carte->begin->label;
	latest->next = (*course)->door;
	(*course)->door = latest;
	carte->begin->value = 0;
	carte->tempo = 1;
	go_nodes(carte, carte->begin, (*course));
	if ((*course)->course1 == NULL)
		return (84);
	return (0);
}

void for_route(course_t *route, course_t *latest)
{
	course_t *tempo = route->course1;

	for (int tri = 3; tri == 3 && tempo != NULL; tempo = tempo->next)
		if (latest->size <= tempo->size)
			tri = 0;
	latest->next = route->course1;
	if (route->course1 != NULL) {
		latest->prev = route->course1->prev;
		route->course1->prev = latest;
	} else
		latest->prev = NULL;
	if (latest->prev == NULL)
		route->course1 = latest;
}
