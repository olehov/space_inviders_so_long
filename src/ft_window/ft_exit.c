/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:46:25 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/12 12:46:27 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_window.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

int	ft_destroy_window(t_window	*window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	printf("destroy_window\n");
	mlx_destroy_display(window->mlx_ptr);
	printf("destroy_display\n");
	free(window->mlx_ptr);
	printf("freed mlx_ptr\n");
	ft_free_game_field(window->game_field);
	printf("freed game field\n");
	free(window);
	printf("freed window\n");
	// ft_free_window(window);
	exit (0);
}

int	ft_close_window(int key, t_window *window)
{
	if (key == XK_Escape)
	{
		ft_destroy_window(window);
	}
	return (0);
}

void	ft_exit(t_window *window)
{
	mlx_key_hook(window->win_ptr, ft_close_window, window);
	mlx_hook(window->win_ptr, DestroyNotify, LeaveWindowMask,
		ft_destroy_window, window);
}
