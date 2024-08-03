/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unsuported_chars.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:12:09 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 16:18:21 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	ft_check_unsuported_chars(t_game_field *game_field)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (game_field->game_field[i][j] == _collectible
				|| game_field->game_field[i][j] == _exit_gate
				|| game_field->game_field[i][j] == _player_start_pos
				|| game_field->game_field[i][j] == _evil_ship
				|| game_field->game_field[i][j] == '0'
				|| game_field->game_field[i][j] == '1')
			{
			}
			else
				return (perror(RED "Error: " RESET "Unsuported character"), -1);
		}
		j = -1;
	}
	return (0);
}
