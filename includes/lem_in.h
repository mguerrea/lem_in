/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:30:37 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 16:27:35 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
#include <stdio.h>
#include <time.h> 


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
void add_node_end(t_node **list, int id);
t_node *last_node(t_node *list);
void del_first(t_node **queue);
void bfs(t_lem_in lem_in);
void throw_error(void);
void print_ant(int ant, char *room);
void send_ants(t_lem_in *lem_in, int **paths);

/*
** PARSER
*/

int get_map(t_lem_in *lem_in);

int is_comment(char *line);
int is_command(char *line);
int is_room(char *line);
int is_link(char *line);

void manage_command(char *line, t_lem_in *lem_in);
void manage_room(char *line, t_lem_in *lem_in);
int manage_link(char *line, t_lem_in *lem_in);

// DEBUG
void show_nodes(t_node *list, t_lem_in lem_in);
void print_tab(int **paths);

void sort_by_distance(t_lem_in *lem_in);

int **find_paths(int depth, int number, t_lem_in lem_in);
void sort_paths(int **paths);
int **keep_best_paths(int **paths, int number);
void send_ants_alt(t_lem_in lem_in);

# endif