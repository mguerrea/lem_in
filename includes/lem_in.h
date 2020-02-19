/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 11:30:37 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 13:12:02 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_node
{
	int				id;
	struct s_node	*nxt;
}				t_node;

typedef struct	s_room
{
	char	*name;
	int		ant;
	int		dist;
	t_node	*adjs;
}				t_room;

typedef struct	s_lem_in
{
	int		ant_nbr;
	int		start;
	int		end;
	t_list	*input;
	t_room	*rooms;
}				t_lem_in;

void			bfs(t_lem_in lem_in);
void			print_ant(int ant, char *room);
void			send_ants(t_lem_in *lem_in, int **paths);

/*
** NODES
*/

int				nodes_len(t_node *list);
void			add_node(t_node **list, int id);
void			add_node_end(t_node **list, int id);
t_node			*last_node(t_node *list);
void			del_first(t_node **queue);

/*
** PARSER
*/

int				get_map(t_lem_in *lem_in);

int				is_comment(char *line);
int				is_command(char *line);
int				is_room(char *line);
int				is_link(char *line);

void			manage_command(char *line, t_lem_in *lem_in);
void			manage_room(char *line, t_lem_in *lem_in);
int				manage_link(char *line, t_lem_in *lem_in);

/*
** PATHS
*/

int				**maximize_flux(int **paths, t_lem_in lem_in);
void			actualize_paths(int **paths, t_lem_in lem_in, int next_ant);
int				**find_paths(t_lem_in lem_in);

/*
** UTILS
*/

void			tab_cpy(int *dest, int *src);
int				tab_len(int *tab);
void			display_anthill(t_lem_in *lem_in);
void			throw_error(char *str);
void			free_lem_in(t_lem_in *lem_in);
void			free_paths(int **paths);

#endif
