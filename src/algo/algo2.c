/*
** EPITECH PROJECT, 2017
** algo
** File description:
** algo
*/

#include "algo.h"

void move_next_node(carte_t *carte, ant_t *ant, int *i)
{
	node_t *tempo = NULL;
	node_t *nouv = NULL;

	if (ant->node == 0)
		return ;
	search_node(carte, ant->course->route[ant->node], &nouv);
	search_node(carte, ant->course->route[ant->node - 1], &tempo);
	if (tempo->value == 0 || tempo == carte->ending) {
		(nouv == carte->begin) ? (carte->begin->value =
		carte->begin->value - 1) : (nouv->value = 0);
		(tempo == carte->ending) ? (carte->ending->value = carte->ending
		->value + 1) : (tempo->value = ant->tag);
		ant->node--;
		((*i) == 1) ? (my_putstr(" P")) : (my_putstr("P"));
		my_put_nbr(ant->tag);
		my_putstr("-");
		my_putstr(tempo->label);
		(*i) = 1;
	}
}

void puting_ants(carte_t *carte, ant_t *ant)
{
	int i = 0;

	for (ant_t *tempo = ant->start; tempo;) {
		move_next_node(carte, tempo, &i);
		if (tempo->node == 0)
			rm_ant(&tempo, ant);
		else
			tempo = tempo->next;
	}
	my_putchar('\n');
}

void epicentre(carte_t *carte, course_t *course)
{
	static int latest_ants = 1;
	ant_t *ant = malloc(sizeof(ant_t));

	ant->start = NULL;
	ant->finish = NULL;
	ant->ants = 0;
	for (; carte->ending->value != carte->ants; puting_ants(carte, ant)) {
		for (course_t *tempo = course; latest_ants <= carte->ants &&
		tempo != NULL && ((carte->ants - latest_ants) >= tempo->size ||
		tempo == course); latest_ants++, tempo = tempo->next)
			sum_ant(ant, latest_ants, tempo);
		if ( latest_ants <= carte->ants)
			puting_ants(carte, ant);
	}
}

void sum_ant(ant_t *ant, int tag, course_t *course)
{
	ant_t *latest = malloc(sizeof(ant_t));

	latest->tag = tag;
	latest->course = course;
	latest->node = course->size - 1;
	latest->next = NULL;
	if (ant->finish == NULL) {
		latest->prev = NULL;
		ant->start = latest;
		ant->finish = latest;
	} else {
		ant->finish->next = latest;
		latest->prev = ant->finish;
		ant->finish = latest;
	}
	ant->ants++;
}

void rm_ant(ant_t **ant, ant_t *ant1)
{
	if ((*ant)->prev != NULL)
		(*ant)->prev->next = (*ant)->next;
	if ((*ant)->next != NULL)
		(*ant)->next->prev = (*ant)->prev;
	if ((*ant) == ant1->start && (*ant) == ant1->finish) {
		ant1->start = NULL;
		ant1->finish = NULL;
		(*ant) = NULL;
	} else {
		if (ant1->start == (*ant))
			ant1->start = (*ant)->next;
		if (ant1->finish == (*ant))
			ant1->finish = (*ant)->prev;
		(*ant) = (*ant)->next;
	}
}
