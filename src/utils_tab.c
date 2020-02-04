/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:21:42 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 18:59:54 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void add_entry(int **path_found, int *path, int max_depth, t_lem_in lem_in)
{
	int i;
	(void)max_depth;

	i = 0;
	while (path_found[i] != NULL)
		i++;
	path_found[i] = malloc(sizeof(int) * lem_in.rooms[lem_in.start].dist * 3);
	int j = 0;
	while (path[j] != -1)
	{
		path_found[i][j] = path[j];
		j++;
	}
	path_found[i][j] = -1;
	path_found[i + 1] = NULL;
}

int number_of_paths(int **path_found)
{
	int i;

	i = 0;
	while (path_found[i] != NULL)
		i++;
	return (i);
}

int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

void tab_cpy(int *dest, int *src)
{
	int i;

	i = 0;
	while (src[i] != -1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = -1;
}
