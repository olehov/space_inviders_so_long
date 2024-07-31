/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:50 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_free_enemy(void *mlx_ptr, t_enemy *enemy)
{
	if (enemy == NULL)
	{
		return ;
	}
	if (enemy->enemy_img != NULL)
	{
		ft_free_image(mlx_ptr, enemy->enemy_img);
	}
	free(enemy);
}
