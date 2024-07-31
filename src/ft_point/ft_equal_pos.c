/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:14:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:18:02 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_point.h"

int	ft_equal_pos(t_point *pos1, t_point *pos2)
{
	if (pos1 == NULL || pos2 == NULL)
	{
		return (-1);
	}
	if (pos1->x == pos2->x && pos1->y == pos2->y)
	{
		return (1);
	}
	return (0);
}
