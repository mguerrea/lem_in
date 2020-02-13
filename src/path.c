/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:06:26 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/13 19:46:09 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	actualize_paths(int **paths, t_lem_in lem_in, int next_ant)
{
	int i;
	int lines;
	int res;

	i = 1;
	lines = lem_in.ant_nbr - next_ant + tab_len(paths[0]);
	while (paths[i])
	{
		res = (lem_in.ant_nbr - next_ant) / (i + 1) + tab_len(paths[i]);
	//	res += ((lem_in.ant_nbr - next_ant) % (i + 1) != 0);
		if (res <= lines + 1)
			lines = res;
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

int		**maximize_flux(int **paths, t_lem_in lem_in)
{
	int i;
	int lines;
	int res;

	i = 1;
	lines = lem_in.ant_nbr + tab_len(paths[0]);
	while (paths[i])
	{
		res = lem_in.ant_nbr / (i + 1) + tab_len(paths[i]);
		res += (lem_in.ant_nbr % (i + 1) != 0);
		if (res <= lines)
			lines = res;
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

void reset_dist(t_lem_in lem_in)
{
	int i;

	i = 0;
	while (lem_in.rooms[i].name)
	{
		if (lem_in.rooms[i].dist != -2)
			lem_in.rooms[i].dist = -1;
		i++;
	}
}

int *find_shortest(t_lem_in lem_in)
{
	t_node *tmp;
	int *path;
	int i;
	int dist;

	tmp = lem_in.rooms[lem_in.start].adjs;
	if (!(path = malloc(sizeof(int) * (lem_in.rooms[lem_in.start].dist + 2))))
		return (NULL);
	i = 1;
	path[0] = lem_in.start;
	dist = lem_in.rooms[lem_in.start].dist;
	while (dist != 0)
	{
		while (lem_in.rooms[tmp->id].dist >= dist || lem_in.rooms[tmp->id].dist == -2)
			tmp = tmp->nxt;
		path[i] = tmp->id;
		i++;
		dist = lem_in.rooms[tmp->id].dist;
		lem_in.rooms[tmp->id].dist = -2;
		tmp = lem_in.rooms[tmp->id].adjs;
	}
	path[i] = -1;
	return (path);
}

int **find_paths(t_lem_in lem_in)
{
	int **paths;
	int *shortest;
	int max;
	int i;

	max = nodes_len(lem_in.rooms[lem_in.start].adjs);
	if (!(paths = malloc(sizeof(int *) * (max + 1))))
		return (NULL);
	i = 0;
	while (i < max)
	{
			reset_dist(lem_in);
	bfs(lem_in);
	if (lem_in.rooms[lem_in.start].dist == -1)
		break;
	shortest = find_shortest(lem_in);
	paths[i] = shortest;
	i++;
	}
	paths[i] = NULL;
	return (paths);
}