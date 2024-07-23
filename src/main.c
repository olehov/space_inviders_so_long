/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:37:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/23 15:13:39 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "./minilibx-linux/mlx.h"
// #include "../headers/ft_window.h"
#include "../headers/so_long.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

int	put_game_field(t_window *window)
{
	int	i;
	int	j;

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
	return (0);
}

void	put_game_exit(t_window *window)
{
	mlx_loop_hook(window->mlx_ptr, ft_exit_gate_animation, window);
}

int	main(void)
{
	int			width;
	int			height;
	t_window	*window;

	width = 1280;
	height = 860;
	window = ft_window_init(width, height);
	if (window == NULL)
	{
		return (0);
	}
	ft_exit(window);
	put_game_field(window);
	put_game_exit(window);
	// mlx_loop_hook(window->mlx_ptr, put_game_exit, window);
	mlx_loop(window->mlx_ptr);
	ft_destroy_window(window);
	return (0);

}
