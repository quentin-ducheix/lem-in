/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while ((s1[i] != '\0') && (s1[i] == s2[i]) && i < n-1) {
		i = i + 1;
	}
	if ((*s1 == '\0' && *s2 == '\0') || (n ==0))
		return (0);
	if (n == 1 || *s1 == '\0' || *s2 == '\0' || i == 0)
		return (s1[i] - s2[i]);
	else
		return (s1[i] - s2[i]);
}

int my_strcmp(char const *s1, char const *s2)
{
	int diff_sub = 0;
	int i = 0;

	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	diff_sub = s1[i] - s2[i];
	return (diff_sub);
}

char *my_strdup(char *src)
{
	int size = my_strlen(src);
	char *str = malloc(sizeof(char) * (size + 1));
	int i = 0;

	while (i < size) {
		str[i] = src[i];
		i++;
	}
	return (str);
}
