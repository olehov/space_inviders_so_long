/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:47:19 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/18 16:21:41 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_game_field.h"
#include "../../ft_libft/headers/libft.h"
#include "../minilibx-linux/mlx.h"

void	ft_free_game_field(void *mlx_ptr, t_game_field *field)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (field == NULL)
		return ;
	if (field->game_field != NULL)
		ft_free_2d_array(field->game_field, field->height);
	if (field->game_field_imgs != NULL)
	{
		while (++i < field->height)
		{
			while (++j < field->width)
			{
				if (field->game_field_imgs[i][j].img_ptr != NULL)
					mlx_destroy_image(mlx_ptr,
						field->game_field_imgs[i][j].img_ptr);
			}
			free(field->game_field_imgs[i]);
			j = -1;
		}
		free(field->game_field_imgs);
	}
	free(field);
}
