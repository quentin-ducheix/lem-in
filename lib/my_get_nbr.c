/*
** EPITECH PROJECT, 2017
** my_get_nbr.c
** File description:
** nbr
*/

int my_get_nbr (char *str)
{
	int nb = 0;
	int verif = 1;
	int i = 0;

	if (str[i] == '-') {
		verif = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10;
		nb = nb + str[i] - 48;
		i++;
	}
	return (nb * verif);
}
