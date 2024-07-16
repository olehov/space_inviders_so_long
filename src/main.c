/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:37:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 15:53:55 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "./minilibx-linux/mlx.h"
#include "../headers/ft_window.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

// int	ft_destroy_so_long(t_window	*window)
// {
// 	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
// 	mlx_destroy_display(window->mlx_ptr);
// 	free(window->mlx_ptr);
// 	free(window);
// 	exit (0);
// }

// int	ft_close_window(int key, t_window *window)
// {
// 	if (key == XK_Escape)
// 	{
// 		ft_destroy_so_long(window);
// 		exit(0);
// 	}
// 	return (0);
// }

// void	ft_close(t_window *window)
// {
// 	mlx_key_hook(window->win_ptr, ft_close_window, window);
// 	mlx_hook(window->win_ptr, DestroyNotify, LeaveWindowMask,
// 		ft_destroy_so_long, window);
// }

int	put_game_field(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->game_field->height)
	{
		mlx_string_put(window->mlx_ptr, window->win_ptr,
			10, (10 + i) * 10, 0x000000FF,
			window->game_field->game_field[i]);
		i++;
	}
	return (0);
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
	// mlx_loop_hook(window->mlx_ptr, put_game_field, window);
	put_game_field(window);
	mlx_loop(window->mlx_ptr);
	ft_destroy_window(window);
	return (0);

}
