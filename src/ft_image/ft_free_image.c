/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:48:21 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:36 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

void	ft_free_image(void *mlx_ptr, t_image *image)
{
	if (image == NULL)
	{
		return ;
	}
	if (image->img_ptr != NULL)
	{
		mlx_destroy_image(mlx_ptr, image->img_ptr);
	}
	free(image);
}
