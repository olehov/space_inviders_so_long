/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_gate_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:55:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/23 14:43:34 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../headers/ft_game_exit.h"
// #include "../../headers/ft_game_field.h"
#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

static void	free_sprite(void *mlx_ptr, t_exit *exit_gate)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (exit_gate->sprite[i] != NULL)
		{
			mlx_destroy_image(mlx_ptr, exit_gate->sprite[i]);
		}
		i++;
	}
}

static t_point	find_position(t_game_field *game_field)
{
	int		x;
	int		y;
	t_point	pos;

	x = 0;
	y = 0;
	pos.x = x;
	pos.y = y;
	while (y < game_field->height)
	{
		while (x < game_field->width)
		{
			if (game_field->game_field[y][x] == _exit_gate)
			{
				pos.x = x * 32;
				pos.y = y * 32;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

t_exit	*ft_exit_gate_init(void *mlx_ptr, t_game_field *game_field)
{
	t_exit	*exit_gate;
	int		size;

	size = 0;
	exit_gate = malloc(sizeof(t_exit));
	if (exit_gate == NULL)
		return (NULL);
	exit_gate->pos = find_position(game_field);
	exit_gate->sprite[0] = mlx_xpm_file_to_image(mlx_ptr, EXIT_PORTAL_1,
			&size, &size);
	if (exit_gate->sprite[0] == NULL)
		return (free(exit_gate), NULL);
	exit_gate->sprite[1] = mlx_xpm_file_to_image(mlx_ptr, EXIT_PORTAL_2,
			&size, &size);
	if (exit_gate->sprite[1] == NULL)
		return (free_sprite(mlx_ptr, exit_gate), free(exit_gate), NULL);
	exit_gate->sprite[2] = mlx_xpm_file_to_image(mlx_ptr, EXIT_PORTAL_3,
			&size, &size);
	if (exit_gate->sprite[2] == NULL)
		return (free_sprite(mlx_ptr, exit_gate), free(exit_gate), NULL);
	exit_gate->is_visible = 1;
	return (exit_gate);
}
