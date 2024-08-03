/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chech_valid_enemy_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:57:25 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 18:08:11 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"

int	ft_chech_valid_enemy_pos(t_game_field *game_field)
{
	int	x;
	int	y;

	x = 0;
	y = game_field->height - 2;
	while (++x < game_field->width - 1)
	{
		if (game_field->game_field[y][x] == _evil_ship)
		{
			return (perror(RED "Error: " RESET "Not playable enemy position"),
				-1);
		}
	}
	return (0);
}
