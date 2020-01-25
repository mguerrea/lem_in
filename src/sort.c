/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:38 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 16:46:44 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem_in.h"

static int tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

void swap(int **a, int **b) 
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

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
static void quickSort(int **arr, int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
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
	dprintf(2, "i = %d\n", i);
	quickSort(paths, 0, i -1);
}

