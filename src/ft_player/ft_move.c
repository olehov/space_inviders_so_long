/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:32:45 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/31 16:27:15 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"
#include <X11/keysym.h>
#include <X11/Xlib.h>

// static void	print_map(t_window *window)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < window->game_field->height)
// 	{
// 		while (j < window->game_field->width)
// 		{
// 			printf("%c", window->game_field->game_field[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		j = 0;
// 		i++;
// 	}
// 	printf("\n");
// }

static int	is_died(t_window *window)
{
	t_enemy	*enemy;
	t_list	*tmp;

	tmp = window->game_field->enemys;
	while (tmp != NULL)
	{
		enemy = tmp->content;
		if (ft_equal_pos(&enemy->pos, &window->game_field->player->pos) == 1)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	move(t_window *window, void (*f)(t_window *))
{
	(*f)(window);
	render_window(window);
	if (ft_equal_pos(&window->game_field->player->pos,
			&window->game_field->exit_gate->pos) == 1
		&& window->game_field->exit_gate->is_visible == 1)
	{
		ft_printf("YOU WON!\n");
		return (mlx_loop_end(window->mlx_ptr));
	}
	if (is_died(window) == 1)
	{
		ft_printf("YOU DIED!\n");
		return (mlx_loop_end(window->mlx_ptr));
	}
	return (0);
}

int	ft_move(int key, t_window *window)
{
	if (key == XK_A || key == XK_a || key == XK_Left)
		return (move(window, ft_move_left));
	else if (key == XK_D || key == XK_d || key == XK_Right)
		return (move(window, ft_move_right));
	else if (key == XK_W || key == XK_w || key == XK_Up)
		return (move(window, ft_move_up));
	else if (key == XK_S || key == XK_s || key == XK_Down)
		return (move(window, ft_move_down));
	else if (key == XK_space)
		return (move(window, ft_shoot));
	else if (key == XK_Escape)
		return (mlx_loop_end(window->mlx_ptr));
	return (0);
}
