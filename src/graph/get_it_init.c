/*
** EPITECH PROJECT, 2017
** graph
** File description:
** graph
*/

#include "my.h"

int get_ants(carte_t *carte, char **arr)
{
	if (my_str_isnum(arr[0]) && !carte->track) {
		if ((carte->ants = my_get_nbr(arr[0])) <= 0)
			return (84);
		carte->track = 1;
		my_putstr("#number_of_ants\n");
		my_put_nbr(carte->ants);
		my_putstr("\n#rooms\n");
	} else
		return (84);
	return (0);
}

int get_door(carte_t *carte, char **arr)
{
	if ((carte->track == 2 || carte->track == 3) &&
	be_node(carte->start, arr[0]) && be_node(carte->start, arr[1])) {
		if (!my_strcmp(arr[0], arr[1]) || be_door(arr, carte, 1) ||
		be_door(arr, carte, 2))
			return (84);
		else {
			for_door(arr, carte, 1);
			for_door(arr, carte, 2);
		}
	} else
		return (84);
	carte->track = 3;
	return (0);
}

int get_node(carte_t *carte, char **arr)
{
	if (be_name_node(arr) && (my_str_isnum(arr[1]) &&
	my_str_isnum(arr[2])) && !be_node(carte->start, arr[0]) &&
	(carte->track == 1 || carte->track == 2)) {
		plus_node(carte, arr);
		carte->track = 2;
		return (0);
	}
	return (84);
}

void ini_carte(carte_t *carte)
{
	carte->ants = 0;
	carte->rooms = 0;
	carte->begin = NULL;
	carte->ending = NULL;
	carte->start = NULL;
	carte->finish = NULL;
	carte->track = 0;
	carte->cmd = 0;
	carte->tp = 0;
}

void getcmd(carte_t *carte, int val)
{
	if (val == 1) {
		carte->cmd = 3;
		return ;
	}
	if (val == 2) {
		carte->cmd = 4;
		return ;
	}
	if (val == 3) {
		if (carte->begin != NULL || carte->track != 2 ||
		carte->finish == NULL)
			return ;
		carte->begin = carte->finish;
	}
	if (val == 4) {
		if (carte->ending != NULL || carte->track != 2
		|| carte->finish == NULL)
			return ;
		carte->ending = carte->finish;
	}
	carte->cmd = 0;
}
