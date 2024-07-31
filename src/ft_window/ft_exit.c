/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:46:25 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:24:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/ft_window.h"
#include "../../headers/so_long.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

// int	ft_destroy_window(t_window	*window)
// {
// 	mlx_loop_end(window->mlx_ptr);
// 	return (1);
// }

// int	hide_portal(t_window *window)
// {
// 	void	*img;
// 	int		w;
// 	int		h;

// 	if (window->game_field->exit_gate->is_visible == 0)
// 	{
// 		window->game_field->exit_gate->is_visible = 1;
// 	}
// 	else
// 	{
// 		img = mlx_xpm_file_to_image(window->mlx_ptr, BACKGROUND, &w, &h);
// 		window->game_field->exit_gate->is_visible = 0;
// 		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, img,
// 			window->game_field->exit_gate->pos.x,
// 			window->game_field->exit_gate->pos.y);
// 		mlx_destroy_image(window->mlx_ptr, img);
// 	}
// 	return (0);
// }

int	ft_exit(t_window *window)
{
	mlx_hook(window->win_ptr, DestroyNotify, LeaveWindowMask,
		mlx_loop_end, window->mlx_ptr);
	return (0);
}
