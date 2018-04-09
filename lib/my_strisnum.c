/*
** EPITECH PROJECT, 2017
** my_strisnum
** File description:
** my_strisnum
*/

int my_str_isnum(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			i = i + 1;
		else
			return (0);
	}
	return (1);
}
