/*
** EPITECH PROJECT, 2017
** graph
** File description:
** graph
*/

#include "my.h"

int be_node(node_t *node, char *str)
{
	node_t *tempo = node;

	for (; tempo; tempo = tempo->next)
		if (my_strcmp(tempo->label, str) == 0)
			return (1);
	return (0);
}

int be_door(char **arr, carte_t *carte, int i)
{
	char *node = NULL;
	char *door = NULL;
	door_t *tempo_door = NULL;
	node_t *tempo = carte->start;

	if (i == 1) {
		node = arr[0];
		door = arr[1];
	} else if (i == 2) {
		node = arr[1];
		door = arr[0];
	}
	for (; tempo; tempo = tempo->next) {
		if (!my_strcmp(tempo->label, node))
			tempo_door = tempo->door;
		for (; tempo_door && !my_strcmp(tempo->label, node); tempo_door
		= tempo_door->next)
			if (!my_strcmp(tempo_door->name, door))
				return (1);
	}
	return (0);
}

int be_name_node(char **arr)
{
	char *str = arr[0];

	for (int i = 0; str[i] != '\0'; i++) {
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 'A' &&
		str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	}
	return (1);
}

int for_door(char **arr, carte_t *carte, int i)
{
	node_t *tempo = carte->start;
	door_t *tempo_door = malloc(sizeof(door_t));
	char *node = NULL;
	char *door = NULL;

	if (i == 1) {
		node = arr[0];
		door = arr[1];
	} else if (i == 2) {
		node = arr[1];
		door = arr[0];
	}
	for (; my_strcmp(node, tempo->label) && tempo != NULL; tempo =
	tempo->next);
	if (tempo == NULL)
		return (0);
	tempo_door->name = door;
	tempo_door->next = tempo->door;
	tempo->door = tempo_door;
	return (1);
}

int plus_node(carte_t *carte, char **arr)
{
	node_t *added = malloc(sizeof(node_t));

	added->value = -3;
	added->label = arr[0];
	added->next = NULL;
	added->door = NULL;
	if (carte->finish != NULL) {
		carte->finish->next = added;
		added->prev = carte->finish;
		carte->finish = added;
	} else {
		added->prev = NULL;
		carte->start = added;
		carte->finish = added;
	}
	carte->rooms++;
	return (0);
}
