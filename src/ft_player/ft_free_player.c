/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:45 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:47 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/ft_player.h"
#include "../../headers/so_long.h"
#include <stddef.h>

void	ft_free_player(void *mlx_ptr, t_player *player)
{
	if (player == NULL)
	{
		return ;
	}
	if (player->player != NULL)
	{
		ft_free_image(mlx_ptr, player->player);
	}
	free(player);
}
