/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:44:26 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/11 11:44:27 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_game_exit.h"

void	ft_free_exit(t_exit *exit_gate)
{
	if (exit_gate == NULL)
	{
		return ;
	}
	if (exit_gate->position != NULL)
	{
		ft_free_point(exit_gate->position);
	}
	if (exit_gate->texture_path != NULL)
	{
		free(exit_gate->texture_path);
	}
}
