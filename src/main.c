/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:38:34 by mguerrea          #+#    #+#             */
/*   Updated: 2019/12/23 14:09:28 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void add_node(t_node **list, int id)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	tmp->nxt = *list;
	tmp->id = id;
	*list = tmp;
}

void show_nodes(t_node *list)
{
	t_node *tmp;

	tmp = list;
	while (tmp)
	{
		dprintf(2, "node = %d\n", tmp->id);
		tmp = tmp->nxt;
	}
}

int main()
{
	t_lem_in lem_in;

	lem_in.ant_nbr = 10;
	lem_in.end = 5;
	lem_in.start = 0;
	lem_in.rooms = malloc(sizeof(t_room) * 7);
	lem_in.rooms[0].name = "0";
	lem_in.rooms[1].name = "1";
	lem_in.rooms[2].name = "2";
	lem_in.rooms[3].name = "3";
	lem_in.rooms[4].name = "4";
	lem_in.rooms[5].name = "5";
	for (int i = 0; i < 6; i++)
	{
		lem_in.rooms[i].dist = -1;
		lem_in.rooms[i].ant = 0;
		lem_in.rooms[i].adjs = NULL;
	}
	add_node(&(lem_in.rooms[0].adjs), 1);
	add_node(&(lem_in.rooms[0].adjs), 2);
	add_node(&(lem_in.rooms[1].adjs), 0);
	add_node(&(lem_in.rooms[1].adjs), 3);
	add_node(&(lem_in.rooms[2].adjs), 0);
	add_node(&(lem_in.rooms[2].adjs), 4);
	add_node(&(lem_in.rooms[2].adjs), 3);
	add_node(&(lem_in.rooms[3].adjs), 1);
	add_node(&(lem_in.rooms[3].adjs), 2);
	add_node(&(lem_in.rooms[3].adjs), 5);
	add_node(&(lem_in.rooms[4].adjs), 2);
	add_node(&(lem_in.rooms[4].adjs), 5);
	add_node(&(lem_in.rooms[5].adjs), 3);
	add_node(&(lem_in.rooms[5].adjs), 4);
//	show_nodes(lem_in.rooms[1].adjs);
	bfs(lem_in);
//	for (int i = 0; i < 6; i++)
//		dprintf(2, "node = %d\t dist = %d\n", i, lem_in.rooms[i].dist);
	if (lem_in.rooms[lem_in.start].dist != -1)
		send_ants(lem_in);
	else
		ft_putendl("ERROR");
}