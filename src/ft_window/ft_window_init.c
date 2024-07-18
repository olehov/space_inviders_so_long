/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:41:20 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/17 16:12:32 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_window.h"
#include "../../headers/ft_image.h"
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

// static int	ft_put_background(t_window *window)
// {
// 	t_image		*img;

// 	img = create_white_background(window);
// 	if (img == NULL)
// 		return (ft_clear_display(window), -1);
// 	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
// 		img->img_ptr, 0, 0);
// 	printf("Image free\n");
// 	ft_free_image(window->mlx_ptr, img);
// 	return (0);
// }



t_window	*ft_window_init(int width, int height)
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
			window->height, "test");
	if (window->win_ptr == NULL)
		return (ft_clear_display(window), NULL);
	window->game_field = ft_init_game_field(window->mlx_ptr, "../maps/map1.ber");
	if (window->game_field == NULL)
		return (ft_clear_display(window), NULL);
	return (window);
}
