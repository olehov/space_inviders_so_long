/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:34:49 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 18:12:21 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"

int	ft_check_player(t_game_field *game_field)
{
	int	i;
	int	j;
	int	player_counter;

	i = 0;
	j = 0;
	player_counter = 0;
	while (++i < game_field->height - 1)
	{
		while (++j < game_field->width - 1)
		{
			if (game_field->game_field[i][j] == _player_start_pos
				&& i != game_field->height - 2)
				return (perror(RED "Error: " RESET ERROR_PLAYER_NOT_FOUND), -1);
			if (game_field->game_field[i][j] == _player_start_pos)
				player_counter++;
		}
		j = 0;
	}
	if (player_counter > 1)
		return (perror(RED "Error: " RESET ERROR_MORE_THAN_ONE "player"), -1);
	if (player_counter < 1)
		return (perror(RED "Error: " RESET ERROR_PLAYER_NOT_FOUND), -1);
	return (0);
}
