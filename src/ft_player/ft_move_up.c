/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:40:34 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:53 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_move_up(t_window *window)
{
	t_point	position;

	if (window == NULL || window->game_field == NULL
		|| window->game_field->player == NULL)
		return ;
	if (window->game_field->player->pos.y > 1)
	{
		position = window->game_field->player->pos;
		window->game_field->game_field[position.y][position.x] = '0';
		window->game_field->game_field[position.y - 1][position.x] = 'P';
		ft_set_position(&window->game_field->player->pos,
			window->game_field->player->pos.x,
			window->game_field->player->pos.y - 1);
		ft_set_position(&window->game_field->player->player->pos,
			window->game_field->player->player->pos.x,
			window->game_field->player->player->pos.y - IMAGE_SIZE);
		window->number_of_movements++;
		ft_printf("Number of movement: %i\n", window->number_of_movements);
	}
}
