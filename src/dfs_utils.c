/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:42:21 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 13:42:50 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset(int *path)
{
	int i;

	i = -1;
	while (path[++i] != -1)
		path[i] = -1;
}

int		is_in_tab(int *path, int current)
{
	int i;

	i = 0;
	while (path[i] != -1)
	{
		if (path[i] == current)
			return (1);
		i++;
	}
	return (0);
}

void	add_to_path(int *path, int current)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i] = current;
}

void	reset_last(int *path)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i - 1] = -1;
}
