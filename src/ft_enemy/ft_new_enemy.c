/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:45:54 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

t_enemy	*ft_new_enemy(void *mlx_ptr, int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (NULL);
	enemy->enemy_img = ft_new_image(mlx_ptr, EVILSHIP_1);
	if (enemy->enemy_img == NULL)
		return (free(enemy), NULL);
	enemy->enemy_img->pos.x = x * IMAGE_SIZE + START_POS_X;
	enemy->enemy_img->pos.y = y * IMAGE_SIZE;
	enemy->pos.x = x;
	enemy->pos.y = y;
	enemy->is_destroyed = 0;
	return (enemy);
}
