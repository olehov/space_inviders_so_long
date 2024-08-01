/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:41:20 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/01 14:58:30 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_clear_display(t_window *window)
{
	if (window->win_ptr != NULL)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	}
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	free(window);
}

t_window	*ft_window_init(int width, int height, char *map_path)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (window == NULL)
		return (NULL);
	window->width = width;
	window->height = height;
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
		return (free(window), NULL);
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->width,
			window->height, "so_long");
	if (window->win_ptr == NULL)
		return (ft_clear_display(window), NULL);
	window->game_field = ft_init_game_field(window->mlx_ptr, map_path);
	if (window->game_field == NULL)
		return (ft_clear_display(window), NULL);
	window->background = ft_screen_background(window->mlx_ptr,
			window->width, window->height);
	window->number_of_movements = 0;
	return (window);
}
