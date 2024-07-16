/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:34:45 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/10 14:34:51 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_player.h"
#include <stddef.h>

void	ft_free_player(t_player *player)
{
	if (player == NULL)
	{
		return ;
	}
	if (player->texture_path != NULL)
	{
		free(player->texture_path);
	}
	if (player->position != NULL)
	{
		ft_free_point(player->position);
	}
	free(player);
}
