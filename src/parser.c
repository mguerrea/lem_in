/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:05:28 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 17:42:43 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int get_ant_number(t_lem_in *lem_in)
{
	char *line;
	int i;

	line = lem_in->input->content;
//	if (get_next_line(STDIN_FILENO, &line) != 1)
//		return (0);
	if ((lem_in->ant_nbr = ft_atoi(line)) == 0)
	{
//		ft_strdel(&line);
		return (0);
	}
	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i])
	{
//		ft_strdel(&line);
		return(0);
	}
//	ft_strdel(&line);
	return(1);
}

// int get_map(t_lem_in *lem_in)
// {
// 	char *line;

// 	line = NULL;
// 	if (!get_ant_number(lem_in))
// 		return (0);
// 	if (!(lem_in->rooms = malloc(sizeof(t_room) * 1)))
// 		return (0);
// 	lem_in->rooms[0].name = NULL;
// 	while (get_next_line(STDIN_FILENO, &line) > 0)
// 	{
// 		if (line && is_command(line))
// 			manage_command(line, lem_in);
// 		else if (line && is_room(line))
// 			manage_room(line, lem_in);
// 		else if (line && is_link(line)) 
// 		{
// 			if (!(manage_link(line, lem_in)))
// 				break ;
// 		}
// 		else if (!line || !is_comment(line))
// 			break ;
// 		ft_strdel(&line);
// 	}
// 	if (line)
// 		ft_strdel(&line);
// 	return (1);
// }

int get_infos(t_lem_in *lem_in)
{
	char *line;
	t_list *tmp;
	int j = 0;

	line = NULL;
	if (!get_ant_number(lem_in))
		return (0);
	if (!(lem_in->rooms = malloc(sizeof(t_room) * 1)))
		return (0);
	lem_in->rooms[0].name = NULL;
	tmp = lem_in->input->next;
	while (tmp)
	{
		line = tmp->content;
		if (line && is_command(line))
			manage_command(line, lem_in);
		else if (line && is_room(line))
			manage_room(line, lem_in);
		else if (line && is_link(line)) 
		{
			if (!(manage_link(line, lem_in)))
				break ;
		}
		else if (!line || !is_comment(line))
			break ;
		tmp = tmp->next;
		j++;
	}
	return (1);
}

int get_map(t_lem_in *lem_in)
{
	char *line;
	t_list *new;
	int ret;
	int j = 0;

	line = NULL;
	lem_in->input = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if(!(new = ft_lstnew(ft_strdup(line), ft_strlen(line) + 1)))
			return (0);
		ft_lstaddback(&(lem_in->input), new);
		ft_strdel(&line);
		j++;
	}
	ret = get_infos(lem_in);
	return (ret);
}