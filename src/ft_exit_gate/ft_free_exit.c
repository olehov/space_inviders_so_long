/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:44:26 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:24:14 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include "../minilibx-linux/mlx.h"

void	ft_free_exit_gate(void *mlx_ptr, t_exit *exit_gate)
{
	int	i;

	i = 0;
	if (exit_gate == NULL)
	{
		return ;
	}
	while (i < 3)
	{
		if (exit_gate->sprite[i] != NULL)
		{
			mlx_destroy_image(mlx_ptr, exit_gate->sprite[i]);
		}
		i++;
	}
	free(exit_gate);
}
