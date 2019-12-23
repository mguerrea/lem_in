/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:30:37 by mguerrea          #+#    #+#             */
/*   Updated: 2019/12/23 11:35:20 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct s_list
{
	int id;
	t_list *nxt;
}				t_list;

typedef struct s_room
{
	char *name;
	int x;
	int y;
	int ant;
	int dist;
	t_list *adjs;
}				t_room;

typedef struct s_lem_in
{
	int ant_nbr;
	int start;
	int end;
	t_room *rooms;
}				t_lem_in;

# endif