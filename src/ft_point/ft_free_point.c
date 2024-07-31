/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:02:55 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:18:03 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_point.h"
#include <stddef.h>

void	ft_free_point(t_point *point)
{
	if (point == NULL)
	{
		return ;
	}
	free(point);
}
