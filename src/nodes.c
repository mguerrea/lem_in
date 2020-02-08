/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:50:00 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 13:48:12 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_node(t_node **list, int id)
{
	t_node *tmp;

	tmp = malloc(sizeof(t_node));
	tmp->nxt = *list;
	tmp->id = id;
	*list = tmp;
}

void	add_node_end(t_node **list, int id)
{
	t_node *new;
	t_node *tmp;

	new = malloc(sizeof(t_node));
	new->nxt = NULL;
	new->id = id;
	tmp = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new;
	}
}

void	del_first(t_node **queue)
{
	t_node *tmp;

	tmp = (*queue)->nxt;
	free(*queue);
	*queue = tmp;
}

t_node	*last_node(t_node *list)
{
	t_node *tmp;

	tmp = list;
	while (tmp->nxt)
		tmp = tmp->nxt;
	return (tmp);
}

int		nodes_len(t_node *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->nxt;
		i++;
	}
	return (i);
}
