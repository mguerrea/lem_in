/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:06:26 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 14:17:57 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	actualize_paths(int **paths, t_lem_in lem_in, int next_ant)
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
			break ;
		i++;
	}
	while (paths[i] && paths[i][0] == lem_in.start)
	{
		tab_cpy(paths[i], &(paths[i][1]));
		i++;
	}
}

void	eliminate_duplicate(int **paths, int number)
{
	int i;
	int room;
	int j;

	i = number + 1;
	room = paths[number][1];
	while (paths[i] && paths[i][1] == room)
		i++;
	j = number + 1;
	if (j == i)
		return ;
	while (paths[i])
	{
		tab_cpy(paths[j], paths[i]);
		i++;
		j++;
	}
	while (paths[j])
	{
		free(paths[j]);
		paths[j] = NULL;
		j++;
	}
}

int		**maximize_flux(int **paths, t_lem_in lem_in)
{
	int i;
	int dist_max;
	int number_of_lines;

	i = 1;
	number_of_lines = lem_in.ant_nbr + tab_len(paths[0]);
	while (paths[i])
	{
		dist_max = tab_len(paths[i]);
		if (lem_in.ant_nbr / (i + 1) + 1 + dist_max <= number_of_lines)
			number_of_lines = lem_in.ant_nbr / (i + 1) + 1 + dist_max;
		else
			break ;
		i++;
	}
	while (paths[i])
	{
		free(paths[i]);
		paths[i] = NULL;
		i++;
	}
	return (paths);
}

int		**keep_best_paths(int **paths, t_lem_in lem_in)
{
	int j;

	sort_paths(paths);
	j = -1;
	while (++j < number_of_paths(paths))
		eliminate_duplicate(paths, j);
	paths = maximize_flux(paths, lem_in);
	return (paths);
}
