/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game_field.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:47:19 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 16:05:34 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/ft_game_field.h"
#include "../../ft_libft/headers/libft.h"

void	ft_free_game_field(t_game_field *field)
{
	if (field == NULL)
	{
		return ;
	}
	if (field->game_field != NULL)
	{
		ft_free_2d_array(field->game_field, field->height);
		printf("Game field width for free:%i\n", field->height);
	}
	// if (field->exit_gate != NULL)
	// {
	// 	ft_free_exit(field->exit_gate);
	// }
	free(field);
}
