/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:53:17 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 19:06:12 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

void reset(int *path)
{
	int i;

	i = -1;
	while (path[++i] != -1)
		path[i] = -1;
}

int is_in_tab(int *path, int current)
{
	int i;

	i = 0;
	while (path[i] != -1)
	{
		if (path[i] == current)
			return (1);
		i++;
	}
	return (0);
}

void add_to_path(int *path, int current)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i] = current;
}

void reset_last(int *path, int jpp)
{
	int i;
	(void)jpp;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i - 1] = -1;
}

void find_recursive(t_lem_in lem_in, int current, int current_depth, int max_depth,
	int number, int *path, int **path_found)
{
	t_node *tmp;

	if (is_in_tab(path, current) || current_depth > max_depth 
	|| tab_len(path) >= lem_in.rooms[lem_in.start].dist * 3 - 1)
		return ;
	else
		add_to_path(path, current);
	if (current == lem_in.end)
	{
		if (number_of_paths(path_found) < number)
			add_entry(path_found, path, max_depth, lem_in);
		reset_last(path, max_depth);
		return ;
	}
	else if (number_of_paths(path_found) < number)
	{
		tmp = lem_in.rooms[current].adjs;
		while (tmp)
		{
			find_recursive(lem_in, tmp->id, current_depth + 1, max_depth, number, path, path_found);
			tmp = tmp->nxt;
		}
	}
	reset_last(path, max_depth);
	return ;
}

int **find_paths(int depth, int number, t_lem_in lem_in)
{
	int **paths_found;
	int *path;
	int i;
	t_node *tmp;
	int new_number;

	tmp = lem_in.rooms[lem_in.start].adjs;
	paths_found = malloc(sizeof(int *) * (number * nodes_len(tmp) + 1));
	paths_found[0] = NULL;
	path = malloc(sizeof(int) * lem_in.rooms[lem_in.start].dist * 3);
	i = -1;
	while (++i < lem_in.rooms[lem_in.start].dist * 3)
		path[i] = -1;
	new_number = number;
	while (tmp)
	{
		path[0] = lem_in.start;
		find_recursive(lem_in, tmp->id, 0, depth, new_number, path, paths_found);
		tmp = tmp->nxt;
		new_number += number;
		reset(path);
	}
	free(path);
	return (paths_found);
}