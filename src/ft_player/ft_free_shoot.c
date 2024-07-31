/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_shoot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:12:45 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:48 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_free_shoot(void *mlx_ptr, t_shoot *shoot)
{
	if (shoot == NULL)
	{
		return ;
	}
	if (shoot->img != NULL)
	{
		ft_free_image(mlx_ptr, shoot->img);
	}
	free(shoot);
}
