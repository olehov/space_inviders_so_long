/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_collectible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:34:24 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 14:23:20 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"

int	ft_check_collectible(t_game_field *game_field)
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
		return (perror(RED "Error: " RESET ERROR_COLLECTIBLE_NOT_FOUND), -1);
	}
	return (0);
}
