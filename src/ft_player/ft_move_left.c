/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:20:28 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 17:55:57 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

// static void	print_map(t_window *window)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < window->game_field->height)
// 	{
// 		while (j < window->game_field->width)
// 		{
// 			printf("%c", window->game_field->game_field[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		j = 0;
// 		i++;
// 	}
// 	printf("\n");
// }

void	ft_move_left(t_window *window)
{
	t_point	position;

	if (window == NULL || window->game_field == NULL
		|| window->game_field->player == NULL)
		return ;
	if (window->game_field->player->pos.x > 1)
	{
		position = window->game_field->player->pos;
		window->game_field->game_field[position.y][position.x] = '0';
		window->game_field->game_field[position.y][position.x - 1] = 'P';
		ft_set_position(&window->game_field->player->pos,
			window->game_field->player->pos.x - 1,
			window->game_field->player->pos.y);
		ft_set_position(&window->game_field->player->player->pos,
			window->game_field->player->player->pos.x - IMAGE_SIZE,
			window->game_field->player->player->pos.y);
		window->number_of_movements++;
		ft_printf("Number of movement: %i\n", window->number_of_movements);
	}
}
