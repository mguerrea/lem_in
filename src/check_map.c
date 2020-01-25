/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:36:03 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/23 17:23:27 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

int is_comment(char *line)
{
	if (line[0] != '#')
		return (0);
	if (line[1] == '#')
		return (0);
	return (1);
}

int is_command(char *line)
{

	if (ft_strncmp(line, "##", 2) != 0)
		return (0);
	if (line[2] && line[2] == '#')
		return (0);
	return (1);
}

int is_room(char *line)
{
	int i;

	i = 0;
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (!(line[i] >= '0' && line[i] <= '9'))
		return (0);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (!(line[i] >= '0' && line[i] <= '9'))
		return (0);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i])
		return (0);
	return (1);
}

int is_link(char *line)
{
	int i;

	i = 0;
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	while (line[i] && line[i] != '-')
		i++;
	if (!line[i])
		return (0);
	i++;
	if (line[i] == '#' || line[i] == 'L')
		return (0);
	return (1);
}