/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:38 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/08 14:14:16 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	swap(int **a, int **b)
{
	int *t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int **arr, int low, int high)
{
	int *pivot;
	int i;
	int j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (tab_len(arr[j]) < tab_len(pivot))
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int **arr, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void		sort_paths(int **paths)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
		i++;
	quick_sort(paths, 0, i - 1);
}
