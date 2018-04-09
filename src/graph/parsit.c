/*
** EPITECH PROJECT, 2017
** graph
** File description:
** graph
*/

#include "my.h"

int parserdt2(carte_t *carte, char *str)
{
	char **arr = conv_array(str, '-');
	int count = 0;
	static int tmp = 0;

	if (arr == NULL)
		return (84);
	for (; arr[count]; count++);
	if (count == 2) {
		if (tmp++ == 0)
			my_putstr("#tunels\n");
		get_door(carte, arr);
		my_putstr(str);
		my_putchar('\n');
	} else if (count == 1)
		get_ants(carte, arr);
	else
		return (84);
	return (0);
}

int parserdt(carte_t *carte, char *str)
{
	int count = 0;
	char **arr = conv_array(str, ' ');

	if (arr == NULL)
		return (84);
	for (; arr[count]; count++);
	if (count == 3) {
		get_node(carte, arr);
		my_putstr(str);
		my_putchar('\n');
	} else if (count == 1)
		if (parserdt2(carte, str) == 84)
			return (84);
	return (0);
}

int parsertp(carte_t *carte, char *str)
{
	if (carte->tp == 1) {
		my_putstr(str);
		my_putchar('\n');
		if (my_strcmp(str, "##start") == 0)
			return (1);
		if (my_strcmp(str, "##end") == 0)
			return (2);
		return (0);
	} else if (carte->tp == 2)
		return (carte->cmd);
	if (parserdt(carte, str) == 84)
		return (84);
	return (carte->cmd);
}

int parser(carte_t *carte)
{
	char *str = NULL;
	size_t i = 0;
	int tmp = 0;

	ini_carte(carte);
	while (getline(&str, &i, stdin) >= 0 && str) {
		if (str[0] == '\0' || str[0] == '\n')
			break;
		str[my_strlen(str) - 1] = '\0';
		if (str[my_strlen(str) - 2] == '\n')
			str[my_strlen(str) - 2] = '\0';
		if (my_strncmp(str, "##", 2) == 0)
			carte->tp = 1;
		else if (str[0] == '#')
			carte->tp = 2;
		else
			carte->tp = 0;
		if ((tmp = parsertp(carte, str)) == 84)
			return (84);
		getcmd(carte, tmp);
	}
	if (carte->start == NULL || carte->begin == NULL || carte->ending ==
	NULL || carte->begin == carte->ending)
			return (84);
	return (0);
}
