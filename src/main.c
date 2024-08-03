/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:37:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 17:36:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../ft_libft/headers/libft.h"
#include "../headers/ft_map_utils.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

void	put_game_exit(t_window *window)
{
	mlx_loop_hook(window->mlx_ptr, ft_exit_gate_animation, window);
}

void	ft_key_handler(t_window *window)
{
	mlx_key_hook(window->win_ptr, ft_move, window);
}

int	ft_close_window_w(t_window *window)
{
	ft_free_game_field(window->mlx_ptr, window->game_field);
	ft_free_image(window->mlx_ptr, window->background);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
	return (0);
}

void	game(t_window *window)
{
	ft_key_handler(window);
	ft_exit(window);
	mlx_loop(window->mlx_ptr);
}

int	main(int argv, char **args)
{
	int			width;
	int			height;
	t_window	*window;

	width = 1920;
	height = 1080;
	if (argv != 2)
		window = ft_window_init(WINDOW_WIDTH, WINDOW_HEIGHT,
				"../maps/valid/map1.ber");
	else
	{
		if (ft_check_valid_path(args[1]) == -1)
			exit(EXIT_FAILURE);
		window = ft_window_init(WINDOW_WIDTH, WINDOW_HEIGHT, args[1]);
	}
	if (window == NULL)
		exit (EXIT_FAILURE);
	put_game_exit(window);
	put_game_field(window);
	render_window(window);
	game(window);
	ft_close_window_w(window);
	return (0);
}
