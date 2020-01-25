/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:53:17 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 17:01:44 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int tab_len2(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

void reset(int *path, int depth)
{
	int i;

	i = -1;
	while (++i < depth)
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

static int tab_len(int **path_found)
{
	int i;

	i = 0;
	while (path_found[i] != NULL)
		i++;
	return (i);
}

void add_entry(int **path_found, int *path, int max_depth, t_lem_in lem_in)
{
	int i;
	(void)max_depth;

	i = 0;
	while (path_found[i] != NULL)
		i++;
	path_found[i] = malloc(sizeof(int) * lem_in.rooms[lem_in.start].dist * 5);
	int j = 0;
	while (path[j] != -1)
	{
		path_found[i][j] = path[j];
		j++;
	}
	path_found[i][j] = -1;
	path_found[i + 1] = NULL;
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
	|| tab_len2(path) >= lem_in.rooms[lem_in.start].dist * 5 - 1)
		return ;
	else
		add_to_path(path, current);
	if (current == lem_in.end)
	{
		if (tab_len(path_found) < number)
			add_entry(path_found, path, max_depth, lem_in);
		reset_last(path, max_depth);
		return ;
	}
	else if (tab_len(path_found) < number)
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

	paths_found = malloc(sizeof(int *) * number + 1);
	paths_found[0] = NULL;
	path = malloc(sizeof(int) * lem_in.rooms[lem_in.start].dist * 5);
	i = -1;
	while (++i < lem_in.rooms[lem_in.start].dist * 5)
		path[i] = -1;
	find_recursive(lem_in, lem_in.start, 0, depth, number, path, paths_found);
	return (paths_found);
}