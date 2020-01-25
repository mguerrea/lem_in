/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:06:26 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 17:02:04 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

/*void sort_paths(int **paths)
{
	int i;
	int *tmp;

	i = 0;
	while (paths[i + 1])
	{
		if (tab_len(paths[i]) > tab_len(paths[i + 1]))
		{
			tmp = paths[i];
			paths[i] = paths[i + 1];
			paths[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}*/

void tab_cpy(int *dest, int *src)
{
	int i;

	i = 0;
	while (src[i] != -1)
	{
		dest[i] = src[i];
		i++;
	}
}

void eliminate_duplicate(int **paths)
{
	int i;
	int room;
	int j;

	i = 1;
	room = paths[0][1];
	while (paths[i])
	{
		if (paths[i][1] != room)
			break;
		i++;
	}
	j = 1;
	while (paths[i])
	{
		tab_cpy(paths[j], paths[i]);
		i++;
		j++;
	}
	while (paths[j])
	{
		free(paths[j]);
		paths[j] = NULL;
		j++;
	}
}

int **keep_best_paths(int **paths, int number)
{
	int i;
	int max;
	(void)number;

	clock_t t = clock();
	sort_paths(paths);
	t = clock() - t; 
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
	dprintf(2, "time taken by sort = %f\n", time_taken);
//	print_tab(paths);
	eliminate_duplicate(paths);
	max = 2 * tab_len(paths[0]);
	i = 0;
	while (paths[i] && tab_len(paths[i]) <= max)
		i++;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		paths[i] = NULL;
		i++;
	}
	return (paths);
}