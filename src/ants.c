/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:50 by mguerrea          #+#    #+#             */
/*   Updated: 2019/12/23 15:20:44 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_ant(int ant, char *room)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(room);
	ft_putstr(" ");
}

int manage_priority(int i, int *ants, t_lem_in lem_in)
{
	int poss_1;
	int poss_2;
	t_node *nodes;

	poss_1 = 0;
	poss_2 = 0;
	nodes = lem_in.rooms[ants[i]].adjs;
	while (nodes)
	{
		if ((lem_in.rooms[nodes->id].ant == 0 || nodes->id == lem_in.end) &&
					lem_in.rooms[nodes->id].dist <= lem_in.rooms[ants[i]].dist)
			poss_1++;
		nodes = nodes->nxt;
	}
	nodes = lem_in.rooms[ants[i + 1]].adjs;
	while (nodes)
	{
		if ((lem_in.rooms[nodes->id].ant == 0 || nodes->id == lem_in.end) &&
					lem_in.rooms[nodes->id].dist <= lem_in.rooms[ants[i + 1]].dist)
			poss_2++;
		nodes = nodes->nxt;
	}
	return (poss_2 < poss_1) ? 0 : 1;
}

void move_one_ant(int i, int *ants, t_lem_in lem_in)
{
	t_node *nodes;

	nodes = lem_in.rooms[ants[i]].adjs;
			while (nodes)
			{
				if ((lem_in.rooms[nodes->id].ant == 0 || nodes->id == lem_in.end) &&
					lem_in.rooms[nodes->id].dist <= lem_in.rooms[ants[i]].dist)
				{
					lem_in.rooms[ants[i]].ant--;
					lem_in.rooms[nodes->id].ant++;
					ants[i] = nodes->id;
					print_ant(i + 1, lem_in.rooms[nodes->id].name);
					break;
				}
				nodes = nodes->nxt;
			}
}

void send_ants(t_lem_in lem_in)
{
	int *ants;
	int i;

	ants = malloc(sizeof(int) * lem_in.ant_nbr);
	i = -1;
	while (++i < lem_in.ant_nbr)
		ants[i] = lem_in.start;
	while (lem_in.rooms[lem_in.end].ant < lem_in.ant_nbr)
	{
		i = -1;
		while (++i < lem_in.ant_nbr)
		{
			if (i < lem_in.ant_nbr - 1 && manage_priority(i, ants, lem_in) == 0)
			{
				move_one_ant(i + 1, ants, lem_in);
				move_one_ant(i, ants, lem_in);
				i++;
			}
			else
				move_one_ant(i, ants, lem_in);
		}
		printf("\n");
	}
}