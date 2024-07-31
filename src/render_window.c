/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:50:41 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/31 16:29:19 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_number_of_movements(t_window *window)
{
	char	*str;
	char	*n_of_m;

	n_of_m = ft_itoa(window->number_of_movements);
	str = ft_strjoin("NUMBER OF MOVEMENTS: ", n_of_m);
	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 100,
		GREY_TEXT, str);
	free(str);
	free(n_of_m);
}

void	render_window(t_window *window)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->background->img_ptr, 0, 0);
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
	ft_put_player(window);
	put_number_of_movements(window);
	ft_put_enemy(window);
}
