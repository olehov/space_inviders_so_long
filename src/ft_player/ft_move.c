/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:32:45 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/26 17:45:50 by ogrativ          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../headers/so_long.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>

static void	put_player_to_screen(t_window *window, t_image *background)
{
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->game_field->player->player->img_ptr,
		window->game_field->player->player->pos.x,
		window->game_field->player->player->pos.y);
}

static void	move(t_window *window, void (*f)(t_window *))
{
	t_image	*background;

	background = ft_new_image(window->mlx_ptr, BACKGROUND);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		background->img_ptr, window->game_field->player->player->pos.x,
		window->game_field->player->player->pos.y);
	(*f)(window);
	put_player_to_screen(window, background);
	if (background != NULL)
	{
		ft_free_image(window->mlx_ptr, background);
	}
}

// void	put_number_of_movements(t_window *window)
// {
// 	char	*str;
// 	char	*n_of_m;

// 	n_of_m = ft_itoa(window->number_of_movements);
// 	str = ft_strjoin("NUMBER OF MOVEMENTS: ", n_of_m);
// 	mlx_string_put(window->mlx_ptr, window->win_ptr, 10, 100,
// 		GREY_TEXT, str);
// 	free(str);
// 	free(n_of_m);
// }

int	ft_move(int key, t_window *window)
{
	if (key == XK_A || key == XK_a || key == XK_Left)
		move(window, ft_move_left);
	if (key == XK_D || key == XK_d || key == XK_Right)
		move(window, ft_move_right);
	if (key == XK_W || key == XK_w || key == XK_Up)
		move(window, ft_move_up);
	if (key == XK_S || key == XK_s || key == XK_Down)
		move(window, ft_move_down);
	if (key == XK_Escape)
		return (ft_destroy_window(window));
	if (ft_equal_pos(&window->game_field->player->pos,
			&window->game_field->exit_gate->pos) == 1)
	{
		render_window(window);
		printf("YOU WON\n");
		ft_destroy_window(window);
	}
	render_window(window);
	return (0);
}
