/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:06:26 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 19:05:32 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void eliminate_duplicate(int **paths, int number)
{
	int i;
	int room;
	int j;

	i = number + 1;
	room = paths[number][1];
	while (paths[i])
	{
		if (paths[i][1] != room)
			break;
		i++;
	}
	j = number + 1;
	if (j == i)
	{
		return ;
	}
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

int **maximize_flux(int **paths, t_lem_in lem_in)
{
	int **new_paths;
	int number;
	int i;
	int j;
	int dist_max;
	int number_of_lines;

	number = number_of_paths(paths);
	new_paths = malloc(sizeof(int *) * (number + 1));
	i = -1;
	while (++i < number + 1)
		new_paths[i] = NULL;
	i = 1;
	new_paths[0] = paths[0];
	j = 1;
	dist_max = tab_len(new_paths[0]);
	number_of_lines = lem_in.ant_nbr + dist_max;
	while (paths[i])
	{
		dist_max = tab_len(paths[i]);
		if (lem_in.ant_nbr / (j + 1) + 1 + dist_max <= number_of_lines)
		{
			number_of_lines = lem_in.ant_nbr / (j + 1) + 1 + dist_max;
			new_paths[j] = paths[i];
			j++;
		}
		else
			break;
		i++;
	}
	while (paths[i])
	{
		free(paths[i]);
		paths[i] = NULL;
		i++;
	}
	free(paths);
	return (new_paths);
}

int **keep_best_paths(int **paths, int number, t_lem_in lem_in)
{
	(void)number;
	int j;

	sort_paths(paths);
	j = -1;
	while (++j < number_of_paths(paths))
		eliminate_duplicate(paths, j);
	
	paths = maximize_flux(paths, lem_in);
	return (paths);
}