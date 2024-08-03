/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:33:07 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 17:26:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"

int	ft_check_walls(int i, int j, t_game_field *game_field)
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
