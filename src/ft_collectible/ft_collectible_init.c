/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:03:08 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/01 14:00:41 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_clear_lst_of_images(void *mlx_ptr, t_list **lst)
{
	t_list	*prev;

	if ((*lst) == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		prev = *lst;
		ft_free_image(mlx_ptr, (*lst)->content);
		*lst = (*lst)->next;
		free(prev);
	}
}

void	ft_put_collectible(t_window *window)
{
	t_image	*img;
	t_list	*tmp;

	tmp = window->game_field->collectible;
	while (tmp != NULL)
	{
		img = tmp->content;
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			img->img_ptr, img->pos.x,
			img->pos.y);
		tmp = tmp->next;
	}
}

static void	*ft_collectible(void *mlx_ptr, t_list **lst, int j, int i)
{
	int		x;
	int		y;
	t_image	*tmp;
	t_list	*last;

	x = j * IMAGE_SIZE + START_POS_X;
	y = i * IMAGE_SIZE;
	if (*lst == NULL)
	{
		*lst = ft_lstnew(ft_new_image(mlx_ptr, COLLECTIBLE));
		if (*lst == NULL)
			return (NULL);
	}
	else
		ft_lstadd_back(lst, ft_lstnew(ft_new_image(mlx_ptr,
					COLLECTIBLE)));
	last = ft_lstlast(*lst);
	tmp = last->content;
	if (tmp->pos.x == 0 && tmp->pos.y == 0)
	{
		tmp->pos.x = x;
		tmp->pos.y = y;
		last->content = tmp;
	}
	else
		return (ft_clear_lst_of_images(mlx_ptr, lst), NULL);
	return (*lst);
}

t_list	*ft_collectible_init(void *mlx_ptr, t_game_field *game_field)
{
	t_list	*lst;
	int		i;
	int		j;

	lst = NULL;
	i = 0;
	j = 0;
	while (++i < game_field->height - 1)
	{
		while (++j < game_field->width - 1)
		{
			if (game_field->game_field[i][j] == _collectible)
			{
				if (ft_collectible(mlx_ptr, &lst, j, i) == NULL)
					return (NULL);
			}
		}
		j = 0;
	}
	return (lst);
}
