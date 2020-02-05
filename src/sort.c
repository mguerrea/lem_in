/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:38 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/04 17:07:12 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static void swap(int **a, int **b) 
{ 
	int *t = *a; 
	*a = *b; 
	*b = t; 
} 

static int partition (int **arr, int low, int high) 
{ 
	int *pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (tab_len(arr[j]) < tab_len(pivot)) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

static void quickSort(int **arr, int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void sort_paths(int **paths)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
		i++;
	quickSort(paths, 0, i - 1);
}
