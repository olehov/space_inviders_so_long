/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:47:19 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 16:31:27 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/ft_game_field.h"
#include "../../headers/so_long.h"
#include "../../ft_libft/headers/libft.h"
#include "../minilibx-linux/mlx.h"

void	free_imgs(void *mlx_ptr, t_game_field *field)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
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

void	ft_free_game_field(void *mlx_ptr, t_game_field *field)
{
	if (field == NULL)
		return ;
	if (field->game_field != NULL)
		ft_free_2d_array(field->game_field, field->height);
	if (field->game_field_imgs != NULL)
		free_imgs(mlx_ptr, field);
	if (field->exit_gate != NULL)
		ft_free_exit_gate(mlx_ptr, field->exit_gate);
	if (field->player != NULL)
		ft_free_player(mlx_ptr, field->player);
	if (field->enemys != NULL)
		ft_clear_lst_of_enemy(mlx_ptr, &field->enemys);
	if (field->collectible != NULL)
		ft_clear_lst_of_images(mlx_ptr, &field->collectible);
	if (field->background != NULL)
		ft_free_image(mlx_ptr, field->background);
	free(field);
}
