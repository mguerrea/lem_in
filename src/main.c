/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:07 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 13:51:34 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

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

	t = clock(); 
	paths = find_paths(lem_in.rooms[lem_in.start].dist * 3, 50, lem_in);
	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
	dprintf(2, "time taken by dfs = %f\n", time_taken);	
	paths = keep_best_paths(paths, 10, lem_in);
	print_tab(paths);
	dprintf(2, "distance = %d\tnb ants = %d\tnb path = %d\n", lem_in.rooms[lem_in.start].dist, lem_in.ant_nbr, number_of_paths(paths));
	dprintf(2, "max dist = %d\n", tab_len(paths[number_of_paths(paths) - 3]));
	dprintf(2, "max dist = %d\n", tab_len(paths[number_of_paths(paths) - 1]));
	int dist_max = tab_len(paths[number_of_paths(paths) - 1]) - 1;
	int number_of_lines = lem_in.ant_nbr / number_of_paths(paths) + dist_max;
	dprintf(2, "number of lines = %d\n", number_of_lines);
//	if (tab_len(paths[0]) > 2 * lem_in.rooms[lem_in.start].dist)
//		send_ants_alt(lem_in);
//	else
		send_ants(&lem_in, paths);
//	dprintf(2, "number of lines = %d\n", number_of_lines);
}