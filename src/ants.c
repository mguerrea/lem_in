/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:04:09 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 16:36:47 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

void print_ant(int ant, char *room)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(room);
	ft_putstr(" ");
}

void send_ants(t_lem_in *lem_in, int **paths)
{
	int i;
	int j;
	int next_ant;
	int total;
	int ant;

	total = 0;
	next_ant = 1;
	while (total != lem_in->ant_nbr)
	{
		i = 0;
	while(paths[i] != NULL)
	{
		j = tab_len(paths[i]) - 2;
		while (j >= 0)
		{
			if ((paths[i][j + 1] == lem_in->end 
			|| lem_in->rooms[paths[i][j + 1]].ant == 0)
			&& (lem_in->rooms[paths[i][j]].ant != 0 
			|| (paths[i][j] == lem_in->start && next_ant <= lem_in->ant_nbr)))
			{
				if (paths[i][j] != lem_in->start)
					ant = lem_in->rooms[paths[i][j]].ant;
				else
				{
					ant = next_ant;
					next_ant++;
				}
				print_ant(ant, lem_in->rooms[paths[i][j + 1]].name);
				lem_in->rooms[paths[i][j + 1]].ant = ant;
				lem_in->rooms[paths[i][j]].ant = 0;
				if (paths[i][j + 1] == lem_in->end)
					total++;
				
			}
			j--;
		}
		i++;
	}
	ft_putchar('\n');
	}
}