/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:01:19 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 16:00:52 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static void	ft_free_e(void *mlx_ptr, t_list **lst, t_list **curent,
		t_list **prev)
{
	if (*prev == NULL)
		*lst = (*curent)->next;
	else
		(*prev)->next = (*curent)->next;
	ft_free_enemy(mlx_ptr, (*curent)->content);
	free(*curent);
	if (*prev == NULL)
		*curent = *lst;
	else
		*curent = (*prev)->next;
}

void	ft_remove_enemy(void *mlx_ptr, t_list **lst, int x, int y)
{
	t_enemy	*tmp;
	t_list	*prev;
	t_list	*curent;

	prev = NULL;
	curent = *lst;
	while (curent != NULL)
	{
		tmp = (t_enemy *)curent->content;
		if (tmp->pos.x == x && tmp->pos.y == y)
		{
			ft_free_e(mlx_ptr, lst, &curent, &prev);
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}
