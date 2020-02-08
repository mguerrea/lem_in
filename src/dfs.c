/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:53:17 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 14:16:39 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_recursive(t_lem_in lem_in, int current, t_dfs *dfs, int depth)
{
	t_node *tmp;

	if (is_in_tab(dfs->path, current) || depth > dfs->max_depth
	|| tab_len(dfs->path) >= lem_in.rooms[lem_in.start].dist * 3 - 1)
		return ;
	else
		add_to_path(dfs->path, current);
	if (current == lem_in.end)
	{
		if (number_of_paths(dfs->paths_found) < dfs->number)
			add_entry(dfs->paths_found, dfs->path, lem_in);
		reset_last(dfs->path);
		return ;
	}
	else if (number_of_paths(dfs->paths_found) < dfs->number)
	{
		tmp = lem_in.rooms[current].adjs;
		while (tmp)
		{
			find_recursive(lem_in, tmp->id, dfs, depth + 1);
			tmp = tmp->nxt;
		}
	}
	reset_last(dfs->path);
	return ;
}

int		**find_paths(int depth, int number, t_lem_in lem_in)
{
	int		i;
	t_node	*tmp;
	t_dfs	dfs;

	tmp = lem_in.rooms[lem_in.start].adjs;
	dfs.paths_found = malloc(sizeof(int *) * (number * nodes_len(tmp) + 1));
	dfs.paths_found[0] = NULL;
	dfs.path = malloc(sizeof(int) * lem_in.rooms[lem_in.start].dist * 3);
	i = -1;
	while (++i < lem_in.rooms[lem_in.start].dist * 3)
		dfs.path[i] = -1;
	dfs.number = number;
	dfs.max_depth = depth;
	while (tmp)
	{
		dfs.path[0] = lem_in.start;
		find_recursive(lem_in, tmp->id, &dfs, 0);
		tmp = tmp->nxt;
		dfs.number += number;
		reset(dfs.path);
	}
	free(dfs.path);
	return (dfs.paths_found);
}
