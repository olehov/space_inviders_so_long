/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:38:23 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 15:01:10 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static t_image	*init_sprite(void *mlx_ptr, int i, int x, int y)
{
	t_image	*img;

	img = NULL;
	if (i == 0)
		img = ft_new_image(mlx_ptr, BACKGROUND);
	else if (i == 1)
		img = ft_new_image(mlx_ptr, EXPLOSION_1);
	else if (i == 2)
		img = ft_new_image(mlx_ptr, EXPLOSION_2);
	else if (i == 3)
		img = ft_new_image(mlx_ptr, EXPLOSION_3);
	else if (i == 4)
		img = ft_new_image(mlx_ptr, EXPLOSION_4);
	else if (i == 5)
		img = ft_new_image(mlx_ptr, EXPLOSION_5);
	if (img != NULL)
	{
		img->pos.x = x * IMAGE_SIZE + START_POS_X;
		img->pos.y = y * IMAGE_SIZE;
		return (img);
	}
	return (NULL);
}

static int	ft_put_sprite(t_window *window, int x, int y, int i)
{
	t_image	*tmp[2];

	tmp[0] = init_sprite(window->mlx_ptr, 0, x, y);
	if (tmp[0] == NULL)
		return (1);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		tmp[0]->img_ptr, tmp[0]->pos.x, tmp[0]->pos.y);
	ft_free_image(window->mlx_ptr, tmp[0]);
	ft_sleep(1);
	tmp[1] = init_sprite(window->mlx_ptr, i, x, y);
	if (tmp[1] == NULL)
		return (1);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		tmp[1]->img_ptr, tmp[1]->pos.x, tmp[1]->pos.y);
	ft_free_image(window->mlx_ptr, tmp[1]);
	return (1);
}

void	ft_destroy_evil_ship_sprite(t_window *window, int x, int y)
{
	int		i;

	i = 0;
	while (++i < 6)
	{
		ft_put_sprite(window, x, y, i);
	}
	ft_remove_enemy(window->mlx_ptr, &window->game_field->enemys, x, y);
	window->game_field->game_field[y][x] = '0';
	if (window->game_field->enemys == NULL)
	{
		window->game_field->collectible = ft_collectible_init(window->mlx_ptr,
				window->game_field);
	}
}

static void	put_laser(t_window *window, t_shoot *shoot)
{
	t_image	*background;
	int		i;

	i = 0;
	background = ft_new_image(window->mlx_ptr, BACKGROUND);
	if (background == NULL)
		return ;
	render_window(window);
	ft_sleep(1);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		background->img_ptr, shoot->img->pos.x, shoot->img->pos.y);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		shoot->img->img_ptr, shoot->img->pos.x, shoot->img->pos.y);
	ft_free_image(window->mlx_ptr, background);
	shoot->pos.y -= 1;
	shoot->img->pos.y -= IMAGE_SIZE;
}

void	ft_shoot(t_window *window)
{
	t_shoot	*shoot;
	int		y;
	int		i;

	i = 0;
	shoot = ft_shoot_init(window->mlx_ptr, window->game_field);
	if (shoot == NULL)
		return ;
	y = shoot->pos.y;
	while (shoot->pos.y > 0)
	{
		if (window->game_field->game_field[y][shoot->pos.x] == _evil_ship)
		{
			put_laser(window, shoot);
			ft_destroy_evil_ship_sprite(window, shoot->pos.x, y);
			break ;
		}
		put_laser(window, shoot);
		y--;
	}
	return (ft_free_shoot(window->mlx_ptr, shoot), render_window(window));
}
