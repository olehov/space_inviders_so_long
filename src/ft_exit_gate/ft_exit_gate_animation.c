/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_gate_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:03:55 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/31 15:21:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

static int	ft_wait(int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		i++;
	}
	return (1);
}

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
		if (ft_wait(10000) == 1)
		{
			mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
				window->game_field->exit_gate->sprite[i],
				window->game_field->exit_gate->pos_on_screen.x,
				window->game_field->exit_gate->pos_on_screen.y);
			i++;
		}
	}
	return (0);
}
