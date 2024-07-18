/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_field.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:55:57 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/17 16:11:17 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_GAME_FIELD_H
# define FT_GAME_FIELD_H

# include "ft_player.h"
# include "ft_image.h"
# include "ft_game_exit.h"

# define BACKGROUND_PATH "../textures/xpm/background.xpm"
# define BOTTOM_H_LINE_PATH "../textures/xpm/bottom_horizontal_line.xpm"
# define BOTTOM_L_CORNER_PATH "../textures/xpm/bottom_left_corner.xpm"
# define BOTTOM_R_CORNER_PATH "../textures/xpm/bottom_right_corner.xpm"
# define LEFT_V_LINE_PATH "../textures/xpm/left_vertical_line.xpm"
# define RIGHT_V_LINE_PATH "../textures/xpm/right_vertical_line.xpm"
# define TOP_H_LINE_PATH "../textures/xpm/top_horizontal_line.xpm"
# define TOP_L_CORNER_PATH "../textures/xpm/top_left_corner.xpm"
# define TOP_R_CORNER_PATH "../textures/xpm/top_right_corner.xpm"

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
	t_image		**game_field_imgs;
	t_player	*player;
	t_exit		*exit_gate;
}	t_game_field;

t_game_field	*ft_init_game_field(void *mlx_ptr, const char *map_path);

void			ft_free_game_field(void *mlx_ptr, t_game_field *field);
/*
Return values:
	1 if player and exit gate in one position
	0 if player and exit gate in different position
*/
int				ft_is_exit(t_player *player, t_exit *exit_gate);

#endif
