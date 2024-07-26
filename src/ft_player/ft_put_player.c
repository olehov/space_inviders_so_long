/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:35:24 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/24 17:16:43 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"
#include <stdio.h>

int	ft_put_player(t_window *window)
{
	if (window == NULL || window->mlx_ptr == NULL || window->win_ptr == NULL
		|| window->game_field == NULL || window->game_field->player == NULL
		|| window->game_field->player->player == NULL)
	{
		perror("Error: Invalid pointer in ft_put_player.\n");
		return (-1);
	}
	printf("Player position: x=%d, y=%d\n",
		window->game_field->player->player->pos.x,
		window->game_field->player->player->pos.y);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->game_field->player->player->img_ptr,
		window->game_field->player->player->pos.x,
		window->game_field->player->player->pos.y);
	return (0);
}

