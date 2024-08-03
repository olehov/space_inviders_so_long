/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_rectangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:35:57 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 18:05:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"
#include <string.h>

int	ft_check_if_rectangle(t_game_field *game_field)
{
	int	i;

	i = 0;
	while (i < game_field->height - 1)
	{
		if ((size_t)game_field->width != ft_strlen(game_field->game_field[i]))
		{
			return (perror(RED "Error: " RESET ERROR_MAP_NOT_RECTANGULAR), -1);
		}
		i++;
	}
	return (0);
}
