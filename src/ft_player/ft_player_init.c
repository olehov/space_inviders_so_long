/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:40:06 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/25 11:19:36 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"

t_player	*ft_player_init(void *mlx_ptr, t_game_field *game_field)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
	{
		return (NULL);
	}
	player->player = ft_new_image(mlx_ptr, PLAYER_SPACESHIP);
	if (player->player == NULL)
	{
		return (free(player), NULL);
	}
	player->player->pos = ft_get_pos_on_screen(game_field, _player_start_pos);
	player->pos = ft_get_pos(game_field, _player_start_pos);
	player->speed = 5;
	return (player);
}
