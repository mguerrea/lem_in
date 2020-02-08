/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:04:09 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 13:03:01 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_ants(int *ants, t_lem_in lem_in)
{
	int i;

	i = 0;
	while (i < lem_in.ant_nbr)
	{
		ants[i] = 0;
		i++;
	}
}

int		is_available(int *path, t_lem_in *lem_in, int *next_ant, int j)
{
	return ((path[j + 1] == lem_in->end ||
		lem_in->rooms[path[j + 1]].ant == 0)
		&& (lem_in->rooms[path[j]].ant != 0
		|| (path[j] == lem_in->start && *next_ant <= lem_in->ant_nbr)));
}

int		move_one_ant(t_lem_in *lem_in, int *path, int ant, int j)
{
	print_ant(ant, lem_in->rooms[path[j + 1]].name);
	lem_in->rooms[path[j + 1]].ant = ant;
	lem_in->rooms[path[j]].ant = 0;
	return (path[j + 1] == lem_in->end);
}

int		move_on_path(int *path, int *next_ant, t_lem_in *lem_in, int *ants)
{
	int j;
	int ant;
	int total;

	total = 0;
	j = tab_len(path) - 1;
	while (--j >= 0)
	{
		if (is_available(path, lem_in, next_ant, j))
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
				total += move_one_ant(lem_in, path, ant, j);
			}
		}
	}
	return (total);
}

void	send_ants(t_lem_in *lem_in, int **paths)
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
