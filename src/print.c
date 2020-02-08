/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:32:48 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 14:06:29 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_anthill(t_lem_in *lem_in)
{
	t_list	*tmp;
	char	*content;

	while (lem_in->input)
	{
		tmp = lem_in->input;
		ft_putendl_fd(lem_in->input->content, 2);
		lem_in->input = lem_in->input->next;
		content = (char *)tmp->content;
		ft_strdel(&content);
		free(tmp);
	}
	ft_putstr_fd("\n", 2);
}

void	print_ant(int ant, char *room)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(room);
	ft_putstr(" ");
}
