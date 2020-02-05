/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:04:09 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/05 16:33:34 by mguerrea         ###   ########.fr       */
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

void actualize_paths(int **paths, t_lem_in lem_in, int next_ant)
{
	int i;
	int dist_max;
	int number_of_lines;
	int res;

	i = 1;
	dist_max = tab_len(paths[0]);
	number_of_lines = lem_in.ant_nbr - next_ant + dist_max;
	while (paths[i])
	{
		dist_max = tab_len(paths[i]);
		res = (lem_in.ant_nbr - next_ant) / (i + 1) + dist_max;
		if (res <= number_of_lines + 1)
			number_of_lines = res;
		else
			break;
		i++;
	}
	while (paths[i] && paths[i][0] == lem_in.start)
	{
		tab_cpy(paths[i], &(paths[i][1]));
		i++;
	}
}

int move_on_path(int *path, int *next_ant, t_lem_in *lem_in, int *ants)
{
	int j;
	int ant;
	int total;

	total = 0;
	j = tab_len(path) - 2;
			while (j >= 0)
			{
				if ((path[j + 1] == lem_in->end ||
				lem_in->rooms[path[j + 1]].ant == 0)
				&& (lem_in->rooms[path[j]].ant != 0
				|| (path[j] == lem_in->start
				&& *next_ant <= lem_in->ant_nbr)))
				{
					if (path[j] != lem_in->start)
						ant = lem_in->rooms[path[j]].ant;
					else
					{
						ant = *next_ant;
						(*next_ant)++;
					}
					if (ants[ant - 1] == 0)
					{
						ants[ant - 1] = 1;
						print_ant(ant, lem_in->rooms[path[j + 1]].name);
						lem_in->rooms[path[j + 1]].ant = ant;
						lem_in->rooms[path[j]].ant = 0;
						if (path[j + 1] == lem_in->end)
							total++;
					}
				}
				j--;
			}
		return (total);
}

void send_ants(t_lem_in *lem_in, int **paths)
{
	int i;
	int next_ant;
	int total;
	int *ants;

	total = 0;
	next_ant = 1;
	ants = malloc(sizeof(int) * lem_in->ant_nbr);
	while (total != lem_in->ant_nbr)
	{
		reset_ants(ants, *lem_in);
		actualize_paths(paths, *lem_in, next_ant - 1);
		i = 0;
		while (paths[i] != NULL)
		{
			total += move_on_path(paths[i], &next_ant, lem_in, ants);	
			i++;
		}
		ft_putchar('\n');
	}
	free(ants);
}