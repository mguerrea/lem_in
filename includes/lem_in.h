/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:30:37 by mguerrea          #+#    #+#             */
/*   Updated: 2019/12/23 13:41:15 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
#include <stdio.h>


typedef struct s_node
{
	int id;
	struct s_node *nxt;
}				t_node;

typedef struct s_room
{
	char *name;
	int x;
	int y;
	int ant;
	int dist;
	t_node *adjs;
}				t_room;

typedef struct s_lem_in
{
	int ant_nbr;
	int start;
	int end;
	t_room *rooms;
}				t_lem_in;

void add_node(t_node **list, int id);
void bfs(t_lem_in lem_in);
void send_ants(t_lem_in lem_in);
void show_nodes(t_node *list);

# endif