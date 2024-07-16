/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:52:06 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/10 15:52:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLECTIBLE_H
# define FT_COLLECTIBLE_H

# include "ft_point.h"
# include "../src/minilibx-linux/mlx.h"

typedef struct s_collectible
{
	void	*texture_path;
	int		is_collected;
	t_point	*position;
}	t_collectible;
/*
Parameters:
	path: path to collectible texture
	x:    x coordinate
	y:    y coordinate
Return value:
	new collectible object
*/
t_collectible	*ft_new_collectible(void *path, int x, int y);

void			ft_free_collectible(t_collectible *item);

#endif