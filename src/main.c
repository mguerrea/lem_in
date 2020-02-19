/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:12:07 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 12:45:20 by mguerrea         ###   ########.fr       */
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
	if (lem_in.ant_nbr == -1)
		throw_error("NO ANTS IN THE ANTHILL");
	if (lem_in.end == -1)
		throw_error("NO END ROOM PROVIDED");
	if (lem_in.start == -1)
		throw_error("NO START ROOM PROVIDED");
	if (lem_in.rooms == NULL || lem_in.rooms[0].name == NULL)
		throw_error("NO ROOMS IN THE ANTHILL");
	if (lem_in.start == lem_in.end)
		throw_error("START AND END ARE THE SAME ROOM");
	return (1);
}

int		main(void)
{
	t_lem_in	lem_in;
	int			**paths;

	init_lem_in(&lem_in);
	if (!get_map(&lem_in))
		throw_error("MALLOC ERROR");
	check_infos(lem_in);
	bfs(lem_in);
	if (lem_in.rooms[lem_in.start].dist == -1)
		throw_error("NO WAY BETWEEN START AND END");
	paths = find_paths(lem_in);
	paths = maximize_flux(paths, lem_in);
	display_anthill(&lem_in);
	send_ants(&lem_in, paths);
}
