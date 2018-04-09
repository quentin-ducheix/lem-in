/*
** EPITECH PROJECT, 2018
** puto
** File description:
** puto
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (0);
}

int my_put_nbr(int nb)
{
	int mod = 0;

	if (nb == 0) {
		my_putchar('0');
		return (0);
	}
	if (nb >= 10) {
		mod = (nb % 10);
		nb = (nb - mod) / 10;
		my_put_nbr(nb);
		my_putchar(mod + 48);
	} else if (nb < 10 && nb > 0)
		my_putchar(48 + (nb % 10));
	return (0);
}

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}

char is_num(char *str)
{
	for (int i = 0; str[i]; i++)
		if (!((str[i] >= '0' && str[i] <= '9')))
			return (0);
	return (1);
}
