/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:17:11 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 12:29:35 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_bfs(t_node **queue, t_node **nodes, t_lem_in *lem_in)
{
	lem_in->rooms[lem_in->end].dist = 0;
	while (*nodes)
	{
		if (lem_in->rooms[(*nodes)->id].dist != -2)
		{
			lem_in->rooms[(*nodes)->id].dist = 1;
			add_node_end(queue, (*nodes)->id);
		}
		*nodes = (*nodes)->nxt;
	}
}

void		bfs(t_lem_in lem_in)
{
	t_node	*queue;
	t_node	*nodes;
	int		current;

	queue = NULL;
	nodes = lem_in.rooms[lem_in.end].adjs;
	init_bfs(&queue, &nodes, &lem_in);
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
