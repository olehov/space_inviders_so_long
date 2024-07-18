/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:39:10 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/18 12:29:26 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_IMAGE_H
# define FT_IMAGE_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
}	t_image;

t_image	*ft_new_image(char *path, int width, int length);

void	ft_free_image(void *mlx_ptr, t_image *image);

#endif