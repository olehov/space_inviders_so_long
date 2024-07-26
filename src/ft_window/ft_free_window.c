/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:41:11 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/26 12:52:23 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "../../headers/ft_window.h"
#include "../../headers/so_long.h"
#include "../../ft_libft/headers/libft.h"

void	ft_free_window(t_window *window)
{
	if (window == NULL)
	{
		return ;
	}
	if (window->mlx_ptr != NULL)
	{
		free(window->mlx_ptr);
	}
	if (window->game_field != NULL)
	{
		ft_free_game_field(window->mlx_ptr, window->game_field);
	}
	free(window);
}
