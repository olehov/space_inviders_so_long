/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:56:19 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:25 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_put_enemy(t_window *window)
{
	t_enemy	*enemy;
	t_list	*tmp;

	tmp = window->game_field->enemys;
	while (tmp != NULL)
	{
		enemy = tmp->content;
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			enemy->enemy_img->img_ptr, enemy->enemy_img->pos.x,
			enemy->enemy_img->pos.y);
		tmp = tmp->next;
	}
}
