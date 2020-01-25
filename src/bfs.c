/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:30:13 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/23 16:50:24 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void bfs(t_lem_in lem_in)
{
	t_node *queue;
	t_node *nodes;
	int current;

	queue = NULL;
	lem_in.rooms[lem_in.end].dist = 0;
	nodes = lem_in.rooms[lem_in.end].adjs;
	while (nodes)
	{
		lem_in.rooms[nodes->id].dist = 1;
		add_node_end(&queue, nodes->id);
		nodes = nodes->nxt;
	}
	current = 1;
	while (queue)
	{
		nodes = lem_in.rooms[queue->id].adjs;
		while (nodes)
		{
			if (lem_in.rooms[nodes->id].dist == -1)
			{
				lem_in.rooms[nodes->id].dist = lem_in.rooms[queue->id].dist + 1;
				add_node_end(&queue, nodes->id);
			}
			nodes = nodes->nxt;
		}
		del_first(&queue);
	}
}