/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:57:14 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 14:57:24 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

int	is_collectible(t_window *window)
{
	t_image	*img;
	t_list	*tmp;

	tmp = window->game_field->collectible;
	while (tmp != NULL)
	{
		img = tmp->content;
		if (ft_equal_pos(&window->game_field->player->player->pos, &img->pos))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
