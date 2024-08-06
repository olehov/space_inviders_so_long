/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:58:34 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/05 13:48:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"
#include <errno.h>

static int	ft_error_check(t_game_field *game_field)
{
	int	error_count;

	errno = ECANCELED;
	error_count = ft_check_if_rectangle(game_field);
	error_count += ft_check_valid_map_size(game_field);
	error_count += ft_check_collectible(game_field);
	error_count += ft_chech_valid_enemy_pos(game_field);
	error_count += ft_check_exit(game_field);
	error_count += ft_check_player(game_field);
	error_count += ft_check_unsuported_chars(game_field);
	if (error_count < 0)
	{
		return (-1);
	}
	return (1);
}

static int	check_if_wall_inside_map(int y, int x, t_game_field *game_field)
{
	if (game_field->game_field[y][x] == '1'
		&& y != 0 && y < game_field->height - 2
		&& x != 0 && x < game_field->width - 2)
	{
		return (-1);
	}
	return (0);
}

int	ft_check_valid_map(t_game_field *game_field)
{
	int	i;
	int	j;
	int	error_count;

	i = -1;
	j = -1;
	if (game_field == NULL)
		return (-1);
	error_count = ft_error_check(game_field);
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (ft_check_walls(i, j, game_field) == -1)
				return (perror(RED "Error: " RESET ERROR_MISSED_WALL), -1);
			if (check_if_wall_inside_map(i, j, game_field))
				return (perror(RED "Error: " RESET
						"Wall can't be inside game field"), -1);
		}
		j = -1;
	}
	errno = ECANCELED;
	if (error_count < 0)
		return (-1);
	return (1);
}
