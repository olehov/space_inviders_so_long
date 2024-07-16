/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:05:41 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/10 15:05:43 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_point.h"

void	ft_set_position(t_point *point, int x, int y)
{
	if (point == NULL)
	{
		return ;
	}
	point->x = x;
	point->y = y;
}
