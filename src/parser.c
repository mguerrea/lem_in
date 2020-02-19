/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:05:28 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 12:40:30 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ant_number(t_lem_in *lem_in)
{
	char	*line;
	int		i;

	line = lem_in->input->content;
	if ((lem_in->ant_nbr = ft_atoi(line)) == 0)
		return (0);
	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i])
		return (0);
	return (1);
}

int		get_infos(t_lem_in *lem_in)
{
	t_list *tmp;

	if (!get_ant_number(lem_in))
		throw_error("NO ANTS IN THE ANTHILL");
	if (!(lem_in->rooms = malloc(sizeof(t_room) * 1)))
		return (0);
	lem_in->rooms[0].name = NULL;
	tmp = lem_in->input->next;
	while (tmp)
	{
		if (is_command(tmp->content))
			manage_command(tmp->content, lem_in);
		else if (is_room(tmp->content))
			manage_room(tmp->content, lem_in);
		else if (is_link(tmp->content))
		{
			if (!(manage_link(tmp->content, lem_in)))
				break ;
		}
		else if (!is_comment(tmp->content))
			break ;
		tmp = tmp->next;
	}
	return (1);
}

int		get_map(t_lem_in *lem_in)
{
	char	*line;
	t_list	*new;
	int		ret;
	int		j;

	j = 0;
	line = NULL;
	lem_in->input = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!(new = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstaddback(&(lem_in->input), new);
		ft_strdel(&line);
		j++;
	}
	ret = get_infos(lem_in);
	return (ret);
}
