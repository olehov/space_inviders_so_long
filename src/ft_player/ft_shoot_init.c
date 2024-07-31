/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shoot_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:58 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:57 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

t_shoot	*ft_shoot_init(void *mlx_ptr, t_game_field *game_field)
{
	t_shoot	*shoot;

	if (game_field->player->pos.y == 1)
		return (NULL);
	shoot = malloc(sizeof(t_shoot));
	if (shoot == NULL)
		return (NULL);
	shoot->img = ft_new_image(mlx_ptr, LASER);
	if (shoot->img == NULL)
		return (free(shoot), NULL);
	shoot->img->pos.x = game_field->player->player->pos.x;
	shoot->img->pos.y = game_field->player->player->pos.y - IMAGE_SIZE;
	shoot->pos.x = game_field->player->pos.x;
	shoot->pos.y = game_field->player->pos.y - 1;
	return (shoot);
}
