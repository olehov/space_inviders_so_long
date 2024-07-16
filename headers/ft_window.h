/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:30:32 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/16 15:58:20 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_WINDOW_H
# define FT_WINDOW_H

# include "ft_game_field.h"
# include "../src/minilibx-linux/mlx.h"

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				number_of_movements;
	int				width;
	int				height;
	t_game_field	*game_field;
}	t_window;

t_window	*ft_window_init(int width, int height);

void		ft_move_up(t_game_field *game_field, t_player *player);
void		ft_move_down(t_game_field *game_field, t_player *player);
void		ft_move_left(t_game_field *game_field, t_player *player);
void		ft_move_right(t_game_field *game_field, t_player *player);
int			ft_move(int key, t_window *window);

t_image		*create_white_background(t_window *window);

/*free allocate memory and exit*/
void		ft_exit(t_window *window);
void		ft_free_window(t_window *window);
int			ft_destroy_window(t_window	*window);

#endif