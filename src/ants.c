/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:04:09 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 15:15:10 by mguerrea         ###   ########.fr       */
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

void reset_ants(int *ants, t_lem_in lem_in)
{
	int i;

	i = 0;
	while (i < lem_in.ant_nbr)
	{
		ants[i] = 0;
		i++;
	}
}

void restrict_paths(int **paths)
{
	int i;
	int max;

	max = tab_len(paths[0]) + 2;
	i = 0;
	while (paths[i] && tab_len(paths[i]) <= max)
		i++;
	while (paths[i] != NULL)
	{
		tab_cpy(paths[i], &(paths[i][1]));
	//	free(paths[i]);
	//	paths[i] = NULL;
		i++;
	}
	dprintf(2, "****************\n");
	print_tab(paths);
}

void send_ants(t_lem_in *lem_in, int **paths)
{
	int i;
	int j;
	int next_ant;
	int total;
	int ant;
	int *ants;
	int restricted;

	total = 0;
	restricted = 0;
	next_ant = 1;
	ants = malloc(sizeof(int) * lem_in->ant_nbr);
	while (total != lem_in->ant_nbr)
	{
		reset_ants(ants, *lem_in);
		if (next_ant > lem_in->ant_nbr * 0.50 && restricted == 0) //&& next_ant < lem_in->ant_nbr + 10)
		{
			restrict_paths(paths);
			restricted = 1;
		}
		i = 0;
		while (paths[i] != NULL)
		{
			j = tab_len(paths[i]) - 2;
			while (j >= 0)
			{
				if ((paths[i][j + 1] == lem_in->end ||
				lem_in->rooms[paths[i][j + 1]].ant == 0)
				&& (lem_in->rooms[paths[i][j]].ant != 0
				|| (paths[i][j] == lem_in->start
				&& next_ant <= lem_in->ant_nbr)))
				{
					if (paths[i][j] != lem_in->start)
						ant = lem_in->rooms[paths[i][j]].ant;
					else
					{
						ant = next_ant;
						next_ant++;
					}
					if (ants[ant - 1] == 0)
					{
						ants[ant - 1] = 1;
						print_ant(ant, lem_in->rooms[paths[i][j + 1]].name);
						lem_in->rooms[paths[i][j + 1]].ant = ant;
						lem_in->rooms[paths[i][j]].ant = 0;
						if (paths[i][j + 1] == lem_in->end)
							total++;
					}
				}
				j--;
			}
			i++;
		}
		ft_putchar('\n');
	}
}