/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:47:07 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_move_right(t_window *window)
{
	t_point	position;

	if (window == NULL || window->game_field == NULL
		|| window->game_field->player == NULL)
		return ;
	if (window->game_field->player->pos.x < window->game_field->width - 2)
	{
		position = window->game_field->player->pos;
		window->game_field->game_field[position.y][position.x] = '0';
		window->game_field->game_field[position.y][position.x + 1] = 'P';
		ft_set_position(&window->game_field->player->pos,
			window->game_field->player->pos.x + 1,
			window->game_field->player->pos.y);
		ft_set_position(&window->game_field->player->player->pos,
			window->game_field->player->player->pos.x + IMAGE_SIZE,
			window->game_field->player->player->pos.y);
		window->number_of_movements++;
		ft_printf("Number of movement: %i\n", window->number_of_movements);
	}
}
