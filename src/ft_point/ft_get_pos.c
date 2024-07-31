/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:33:55 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:18:04 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

t_point	ft_get_pos_on_screen(t_game_field *game_field, char obj)
{
	int		x;
	int		y;
	t_point	pos;

	x = 0;
	y = 0;
	pos.x = x;
	pos.y = y;
	while (y < game_field->height)
	{
		while (x < game_field->width)
		{
			if (game_field->game_field[y][x] == obj)
			{
				pos.x = (x * IMAGE_SIZE) + START_POS_X;
				pos.y = y * IMAGE_SIZE;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

t_point	ft_get_pos(t_game_field *game_field, char obj)
{
	int		x;
	int		y;
	t_point	pos;

	x = 0;
	y = 0;
	pos.x = x;
	pos.y = y;
	while (y < game_field->height)
	{
		while (x < game_field->width)
		{
			if (game_field->game_field[y][x] == obj)
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}
