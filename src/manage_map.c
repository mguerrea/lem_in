/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:46:21 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 13:47:04 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	manage_command(char *line, t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (lem_in->rooms[i].name != NULL)
		i++;
	if (ft_strncmp(line, "##start", 7) == 0)
		lem_in->start = i;
	else if (ft_strncmp(line, "##end", 5) == 0)
		lem_in->end = i;
}

void	manage_room(char *line, t_lem_in *lem_in)
{
	int i;
	int len;

	i = 0;
	while (lem_in->rooms[i].name != NULL)
		i++;
	if (!(lem_in->rooms = ft_realloc(lem_in->rooms, sizeof(t_room) * (i + 1),
		sizeof(t_room) * (i + 2))))
		throw_error();
	len = ft_strchr(line, ' ') - line;
	lem_in->rooms[i].name = ft_strsub(line, 0, len);
	lem_in->rooms[i + 1].name = NULL;
	lem_in->rooms[i].dist = -1;
	lem_in->rooms[i].ant = 0;
	lem_in->rooms[i].adjs = NULL;
}

int		manage_link(char *line, t_lem_in *lem_in)
{
	char	**rooms;
	int		id_0;
	int		id_1;
	int		i;

	rooms = ft_strsplit(line, '-');
	id_0 = -1;
	id_1 = -1;
	i = 0;
	while (lem_in->rooms[i].name && (id_0 == -1 || id_1 == -1))
	{
		if (ft_strcmp(lem_in->rooms[i].name, rooms[0]) == 0)
			id_0 = i;
		else if (ft_strcmp(lem_in->rooms[i].name, rooms[1]) == 0)
			id_1 = i;
		i++;
	}
	if (id_0 == -1 || id_1 == -1)
		return (0);
	add_node(&(lem_in->rooms[id_0].adjs), id_1);
	add_node(&(lem_in->rooms[id_1].adjs), id_0);
	free_tab(rooms);
	return (1);
}
