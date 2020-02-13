/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:07 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/13 19:46:52 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_lem_in(t_lem_in *lem_in)
{
	lem_in->ant_nbr = -1;
	lem_in->end = -1;
	lem_in->start = -1;
	lem_in->rooms = NULL;
}

int		check_infos(t_lem_in lem_in)
{
	if (lem_in.ant_nbr == -1 || lem_in.end == -1
	|| lem_in.start == -1 || lem_in.rooms == NULL
	|| lem_in.rooms[0].name == NULL)
		return (0);
	return (1);
}

int main(void)
{
	t_lem_in	lem_in;
	int			**paths;

	init_lem_in(&lem_in);
	if (!get_map(&lem_in) || check_infos(lem_in) == 0)
		throw_error();
	bfs(lem_in);
	if (lem_in.rooms[lem_in.start].dist == -1)
		throw_error();
	paths = find_paths(lem_in);
	paths = maximize_flux(paths, lem_in);
	display_anthill(&lem_in);
	send_ants(&lem_in, paths);
}