/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:40:34 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/26 16:45:25 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"

static void	print_map(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < window->game_field->height)
	{
		while (j < window->game_field->width)
		{
			printf("%c", window->game_field->game_field[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("\n");
}

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
		print_map(window);
	}
}
