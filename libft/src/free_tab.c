/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:10:47 by mguerrea          #+#    #+#             */
/*   Updated: 2020/01/23 17:11:23 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		ft_strdel(&(array[i]));
		i++;
	}
	free(array);
}