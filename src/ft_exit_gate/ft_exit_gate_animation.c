/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_gate_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:03:55 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/23 14:42:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../headers/ft_game_exit.h"
// #include "../../headers/ft_window.h"
#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

int	ft_exit_gate_animation(t_window *window)
{
	int	i;
	int	delay;

	i = 0;
	delay = 0;
	if (window->game_field->exit_gate->is_visible == 0)
	{
		return (0);
	}
	while (i < 3)
	{
		while (delay < 50000)
		{
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
				window->game_field->exit_gate->sprite[i],
				window->game_field->exit_gate->pos.x,
				window->game_field->exit_gate->pos.y);
			delay++;
		}
		delay = 0;
		i++;
	}
	return (0);
}