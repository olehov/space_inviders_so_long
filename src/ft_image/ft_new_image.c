/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:58:43 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:38 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

t_image	*ft_new_image(void *mlx_ptr, char *path)
{
	t_image	*img;

	img = malloc(sizeof(t_image));
	if (img == NULL)
	{
		return (NULL);
	}
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->height = IMAGE_SIZE;
	img->width = IMAGE_SIZE;
	return (img);
}
