/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:47:10 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 17:47:37 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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