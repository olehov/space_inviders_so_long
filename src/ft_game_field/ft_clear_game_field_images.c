/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_game_field_images.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:05:35 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/25 15:38:25 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"

void	ft_clear_game_field_images(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (window == NULL || window->game_field == NULL
		|| window->game_field->game_field_imgs == NULL)
		return ;
	if (window->game_field->game_field_imgs != NULL)
	{
		while (i < window->game_field->height)
		{
			while (j < window->game_field->width)
			{
				if (window->game_field->game_field_imgs[i][j].img_ptr != NULL)
				{
					ft_free_image(window->mlx_ptr,
						&window->game_field->game_field_imgs[i][j]);
				}
				j++;
			}
			// free(window->game_field->game_field_imgs[i]);
			j = 0;
			i++;
		}
	}
}
