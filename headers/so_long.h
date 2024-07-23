/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:35:49 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/23 16:44:09 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_point.h"
# include "ft_color_utils.h"
# include "ft_textures.h"
# include "../src/minilibx-linux/mlx.h"

enum e_game_field
{
	_collectible = 'C',
	_exit_gate = 'E',
	_player_start_pos = 'P'
};

typedef struct s_exit
{
	void	*sprite[4];
	int		is_visible;
	t_point	pos;
}	t_exit;

typedef struct s_image
{
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
	t_point	pos;
}	t_image;

typedef struct s_collectible
{
	t_image	*item;
	int		is_collected;
	t_point	*position;
}	t_collectible;

/*on game field varible means array game_field*/
typedef struct s_player
{
	t_image	*player;
	t_point	*pos;
	t_point	*on_game_field;
}	t_player;

typedef struct s_enemy
{
	t_image	*enemy;
	t_point	*pos;
	t_point	*on_game_field;
	int		is_destroyed;
}	t_enemy;

typedef struct s_game_field
{
	char		**game_field;
	int			height;
	int			width;
	t_image		**game_field_imgs;
	t_player	*player;
	t_exit		*exit_gate;
}	t_game_field;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				number_of_movements;
	int				width;
	int				height;
	t_game_field	*game_field;
}	t_window;

t_window		*ft_window_init(int width, int height);
t_game_field	*ft_init_game_field(void *mlx_ptr, const char *map_path);
t_exit			*ft_exit_gate_init(void *mlx_ptr, t_game_field *game_field);
void			ft_player_init(t_player *player, char *texture_path,
					int x, int y);

t_image			*ft_new_image(void *mlx_ptr, char *path);
t_collectible	*ft_new_collectible(void *path, int x, int y);

void			ft_move_up(t_game_field *game_field, t_player *player);
void			ft_move_down(t_game_field *game_field, t_player *player);
void			ft_move_left(t_game_field *game_field, t_player *player);
void			ft_move_right(t_game_field *game_field, t_player *player);
int				ft_move(int key, t_window *window);

/*
Return values:
	1 if player and exit gate in one position
	0 if player and exit gate in different position
*/
int				ft_is_exit(t_player *player, t_exit *exit_gate);
int				ft_check_valid_map(t_game_field *game_field);

t_point			ft_get_player_pos(t_player player);
int				ft_exit_gate_animation(t_window *window);

/*free allocate memory and exit*/
void			ft_free_image(void *mlx_ptr, t_image *image);
void			ft_free_collectible(t_collectible *item);
void			ft_free_game_field(void *mlx_ptr, t_game_field *field);
void			ft_free_player(t_player *player);
void			ft_exit(t_window *window);
void			ft_free_window(t_window *window);
void			ft_free_exit_gate(void *mlx_ptr, t_exit *exit_gate);
int				ft_destroy_window(t_window	*window);


#endif
