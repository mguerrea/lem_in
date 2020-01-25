/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:07 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 17:01:56 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

void show_nodes(t_node *list, t_lem_in lem_in)
{
	t_node *tmp;
	int i;

	tmp = list;
	while (tmp)
	{
		dprintf(2, "node = %d %s\t", tmp->id, lem_in.rooms[tmp->id].name);
		i = 0;
		dprintf(2, "dist = %d\n", lem_in.rooms[tmp->id].dist);
		tmp = tmp->nxt;
	}
}

void print_tab(int **paths)
{
	int i = 0;
	while (paths[i])
	{
		int j = 0;
		while (paths[i][j] != -1)
		{
			dprintf(2, "%d ", paths[i][j]);
			j++;
		}
		dprintf(2, "\n");
		i++;
	}
}

void init_lem_in(t_lem_in *lem_in)
{
	lem_in->ant_nbr = -1;
	lem_in->end = -1;
	lem_in->start = -1;
	lem_in->rooms = NULL;
}

int check_infos(t_lem_in lem_in)
{
	if (lem_in.ant_nbr == -1 || lem_in.end == -1
	|| lem_in.start == -1 || lem_in.rooms == NULL
	|| lem_in.rooms[0].name == NULL)
		return (0);
	return (1);
}

int main()
{
	t_lem_in lem_in;
	int **paths;

	clock_t t; 
    t = clock(); 
	init_lem_in(&lem_in);
	if (!get_map(&lem_in) || check_infos(lem_in) == 0)
		throw_error();
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
	dprintf(2, "time taken by parser = %f\n", time_taken);
	t = clock(); 
	bfs(lem_in);
	if (lem_in.rooms[lem_in.start].dist == -1)
		throw_error();
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
	dprintf(2, "time taken by bfs = %f\n", time_taken);
//	dprintf(2, "distance = %d\n", lem_in.rooms[lem_in.start].dist);
	t = clock(); 
	paths = find_paths(30, 1000, lem_in);
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
	dprintf(2, "time taken by dfs = %f\n", time_taken);	
	paths = keep_best_paths(paths, 10);
//	print_tab(paths);
	if (tab_len(paths[0]) > 2 * lem_in.rooms[lem_in.start].dist)
		send_ants_alt(lem_in);
	else
		send_ants(&lem_in, paths);
}