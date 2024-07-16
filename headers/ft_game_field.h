/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_field.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:55:57 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 15:54:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_GAME_FIELD_H
# define FT_GAME_FIELD_H

# include "ft_player.h"
# include "ft_image.h"
# include "ft_game_exit.h"

enum e_game_field
{
	_collectible = 'C',
	_exit_gate = 'E',
	_player_start_pos = 'P'
};

typedef struct s_game_field
{
	char		**game_field;
	int			height;
	int			width;
	t_player	*player;
	t_exit		*exit_gate;
}	t_game_field;

t_game_field	*ft_init_game_field(const char *map_path);

void			ft_free_game_field(t_game_field *field);
/*
Return values:
	1 if player and exit gate in one position
	0 if player and exit gate in different position
*/
int				ft_is_exit(t_player *player, t_exit *exit_gate);

#endif
