/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "algo.h"

int main(int ac, char **av)
{
	(void)av;
	carte_t *carte = malloc(sizeof(carte_t));
	course_t *route = malloc(sizeof(course_t));

	if (ac == 1) {
		if (parser(carte) == 84)
			return (84);
		my_putstr("#moves\n");
		if (search_courses(carte, &route) == 84)
			return (84);
		rst_carte(carte);
		epicentre(carte, route->course1);
	} else
		return (84);
	return (0);
}
