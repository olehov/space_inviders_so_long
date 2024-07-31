/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:00:28 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:20 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

t_list	*ft_enemy_init(void *mlx_ptr, t_game_field *game_field)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	lst = NULL;
	while (++i < game_field->height - 1)
	{
		while (++j < game_field->width - 1)
		{
			if (game_field->game_field[i][j] == _evil_ship)
			{
				if (lst == NULL)
					lst = ft_lstnew(ft_new_enemy(mlx_ptr, j, i));
				else
					ft_lstadd_back(&lst, ft_lstnew(
							ft_new_enemy(mlx_ptr, j, i)));
				if (lst->content == NULL)
					return (ft_clear_lst_of_enemy(mlx_ptr, &lst), NULL);
			}
		}
		j = 0;
	}
	return (lst);
}
