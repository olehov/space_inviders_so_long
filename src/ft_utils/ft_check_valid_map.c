/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:58:34 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/01 16:55:44 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"

static int	ft_check_walls(int i, int j, t_game_field *game_field)
{
	if (i == 0 && game_field->game_field[i][j] != '1')
	{
		return (-1);
	}
	else if (j == 0 && game_field->game_field[i][j] != '1')
	{
		return (-1);
	}
	else if (i == game_field->height - 1
		&& game_field->game_field[i][j] != '1')
	{
		return (-1);
	}
	else if (j == game_field->width - 1
		&& game_field->game_field[i][j] != '1')
	{
		return (-1);
	}
	return (1);
}

static int	ft_check_collectible(t_game_field *game_field)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	j = -1;
	counter = 0;
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (game_field->game_field[i][j] == 'C')
				counter++;
		}
		j = -1;
	}
	if (counter < 1)
	{
		ft_putstr_fd("Error: Collectible not found\n", 1);
		return (-1);
	}
	return (1);
}

static int	ft_check_player(t_game_field *game_field)
{
	int	i;
	int	j;
	int	player_counter;

	i = -1;
	j = -1;
	player_counter = 0;
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (game_field->game_field[i][j] == _player_start_pos)
				player_counter++;
		}
		j = -1;
	}
	if (player_counter > 1)
		return (ft_putstr_fd("Error: More than 1 player\n", 1), -1);
	if (player_counter < 1)
		return (ft_putstr_fd("Error: Player not found\n", 1), -1);
	return (1);
}

static int	ft_check_exit(t_game_field *game_field)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	j = -1;
	counter = 0;
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (game_field->game_field[i][j] == _exit_gate)
				counter++;
		}
		j = -1;
	}
	if (counter > 1)
		return (ft_putstr_fd(RED "Error: " RESET ERROR_MORE_THAN_ONE "exit\n",
				STDERR_FILENO), -1);
	if (counter < 1)
		return (ft_putstr_fd(RED "Error: " RESET ERROR_EXIT_NOT_FOUND,
				STDERR_FILENO), -1);
	return (1);
}

static int	ft_check_if_rectangle(t_game_field *game_field)
{
	int	i;

	i = 0;
	while (i < game_field->height - 1)
	{
		if (ft_strlen(game_field->game_field[i])
			!= ft_strlen(game_field->game_field[i + 1]))
		{
			ft_printf(RED "ERROR: " RESET ERROR_MAP_NOT_RECTANGULAR);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_check_valid_map(t_game_field *game_field)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (game_field == NULL)
		return (-1);
	if (ft_check_if_rectangle(game_field) == -1
		|| ft_check_collectible(game_field) == -1
		|| ft_check_exit(game_field) == -1
		|| ft_check_player(game_field) == -1)
		return (-1);
	while (++i < game_field->height)
	{
		while (++j < game_field->width)
		{
			if (ft_check_walls(i, j, game_field) == -1)
				return (-1);
		}
		j = -1;
	}
	return (1);
}
