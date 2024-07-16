/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_exit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:08:11 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/09 14:08:16 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_EXIT_H
# define FT_GAME_EXIT_H

# include "ft_point.h"

typedef struct s_exit
{
	char	*texture_path;
	int		is_visible;
	t_point	*position;
}	t_exit;

void	ft_game_field_exit(void);
void	ft_free_exit(t_exit *exit_gate);

#endif