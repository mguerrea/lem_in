/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:50 by mguerrea          #+#    #+#             */
/*   Updated: 2019/12/23 13:56:39 by mguerrea         ###   ########.fr       */
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

void send_ants(t_lem_in lem_in)
{
	int *ants;
	int i;
	t_node *nodes;

	ants = malloc(sizeof(int) * lem_in.ant_nbr);
	i = -1;
	while (++i < lem_in.ant_nbr)
		ants[i] = lem_in.start;
	while (lem_in.rooms[lem_in.end].ant < lem_in.ant_nbr)
	{
		i = -1;
		while (++i < lem_in.ant_nbr)
		{
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
		printf("\n");
	}
}