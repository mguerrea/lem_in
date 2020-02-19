/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:17:59 by mguerrea          #+#    #+#             */
/*   Updated: 2020/02/19 12:38:23 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	throw_error(char *error)
{
	if (error)
		ft_putendl_fd(error, 2);
	else
		ft_putendl_fd("ERROR", 2);
	exit(1);
}
