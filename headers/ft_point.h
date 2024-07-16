/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:12:17 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/09 13:12:20 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/*
Return values:
	-1 if one argument is empty
	0  if pos1 and pos2 is different
	1  if pos1 and pos2 is equal
*/
int		ft_equal_pos(t_point *pos1, t_point *pos2);

void	ft_set_position(t_point *point, int x, int y);
void	ft_free_point(t_point *point);

#endif