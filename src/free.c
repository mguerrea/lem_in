/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:02:41 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 13:15:41 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_nodes(t_node *nodes)
{
	t_node *tmp;

	while (nodes)
	{
		tmp = nodes->nxt;
		free(nodes);
		nodes = tmp;
	}
}

void	free_lem_in(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (lem_in->rooms[i].name != NULL)
	{
		ft_strdel(&(lem_in->rooms[i].name));
		free_nodes(lem_in->rooms[i].adjs);
		i++;
	}
	free(lem_in->rooms);
}

void	free_paths(int **paths)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
