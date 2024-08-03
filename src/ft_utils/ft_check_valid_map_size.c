/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:25:42 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 17:15:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"

static int	check_max_field_size(t_game_field *game_field)
{
	const int	max_height = WINDOW_HEIGHT / IMAGE_SIZE;
	const int	max_width = (WINDOW_WIDTH - START_POS_X) / IMAGE_SIZE;

	if (max_height < game_field->height || max_width < game_field->width)
	{
		return (perror(RED "Error: " RESET "Map size more than window size"),
			-1);
	}
	return (0);
}

int	ft_check_valid_map_size(t_game_field *game_field)
{
	const int	min_height = 4;
	const int	min_width = 4;
	const int	min_win_height = (min_height + 1) * IMAGE_SIZE;
	const int	min_win_width = (min_width + 1) * IMAGE_SIZE + START_POS_X;

	if (min_win_height > WINDOW_HEIGHT || min_win_width > WINDOW_WIDTH)
		return (perror(RED "Error: " RESET "Window size less than minimal"),
			-1);
	if (min_height > game_field->height || min_width > game_field->width)
		return (perror(RED "Error: " RESET "Map size less than minimal"), -1);
	return (check_max_field_size(game_field));
}
