/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:35:34 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 18:02:00 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	put_game_field(t_window *window)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < window->game_field->height)
	{
		while (j < window->game_field->width)
		{
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
				window->game_field->game_field_imgs[i][j].img_ptr,
				window->game_field->game_field_imgs[i][j].pos.x,
				window->game_field->game_field_imgs[i][j].pos.y);
			j++;
		}
		j = 0;
		i++;
	}
}
