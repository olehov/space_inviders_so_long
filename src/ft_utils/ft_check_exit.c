/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:35:27 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/02 15:43:22 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_map_utils.h"
#include "../../ft_libft/headers/libft.h"
#include "../../headers/ft_color_utils.h"

int	ft_check_exit(t_game_field *game_field)
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
		return (perror(RED "Error: " RESET ERROR_MORE_THAN_ONE "exit"), -1);
	if (counter < 1)
		return (perror(RED "Error: " RESET ERROR_EXIT_NOT_FOUND), -1);
	return (0);
}
