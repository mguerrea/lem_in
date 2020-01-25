/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:48:41 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/25 16:46:35 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void partition2(t_node **prev, t_node **head, t_node **tail)
{
	t_node *tmp;

	if (*prev) 
        (*prev)->nxt = (*head)->nxt; 
    tmp = (*head)->nxt; 
    (*head)->nxt = NULL; 
    (*tail)->nxt = *head; 
    *tail = *head; 
    *head = tmp;
}


static t_node *partition(t_node *head, t_node *end, t_node **newHead, t_node **newEnd, t_lem_in lem_in) 
{ 
    t_node *prev; 
	t_node *tail;

	prev = NULL;
	tail = end;
    while (head != end) 
    {
		if(lem_in.rooms[head->id].dist < lem_in.rooms[end->id].dist)
            //ft_strcmp(((t_node *)(head->dist))->name,
			//	((t_data *)(end->content))->name) < 0) 
        { 
            if ((*newHead) == NULL) 
                (*newHead) = head; 
            prev = head;   
            head = head->nxt;
		} 
        else 
			partition2(&prev, &head, &tail);
    }
    if ((*newHead) == NULL) 
        (*newHead) = end; 
    (*newEnd) = tail; 
    return end; 
}

static t_node	*quickSortRecur(t_node *head, t_node *end, t_lem_in lem_in) 
{ 
    t_node *newHead = NULL;
	t_node *newEnd = NULL;
	t_node *pivot;
	t_node *tmp; 
  
  	if (!head || head == end) 
        return head;  
	newHead = NULL;
	newEnd = NULL;
    pivot = partition(head, end, &newHead, &newEnd, lem_in); 
    if (newHead != pivot) 
    { 
        tmp = newHead; 
        while (tmp->nxt != pivot) 
            tmp = tmp->nxt; 
        tmp->nxt = NULL; 
       	newHead = quickSortRecur(newHead, tmp, lem_in); 
        tmp = last_node(newHead); 
        tmp->nxt =  pivot; 
    } 
    pivot->nxt = quickSortRecur(pivot->nxt, newEnd, lem_in); 
    return newHead; 
}

void sort_by_distance(t_lem_in *lem_in)
{
    int i;

    i = 0;
    while (lem_in->rooms[i].name != NULL)
    {
        lem_in->rooms[i].adjs = quickSortRecur(lem_in->rooms[i].adjs, last_node(lem_in->rooms[i].adjs), *lem_in);
        i++;
    }
}