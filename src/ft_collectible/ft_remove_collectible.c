/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_collectible.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:57:53 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 15:57:33 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

static void	ft_free_c(void *mlx_ptr, t_list **lst, t_list **curent,
		t_list **prev)
{
	if (*prev == NULL)
		*lst = (*curent)->next;
	else
		(*prev)->next = (*curent)->next;
	ft_free_image(mlx_ptr, (*curent)->content);
	free(*curent);
	if (*prev == NULL)
		*curent = *lst;
	else
		*curent = (*prev)->next;
}

void	ft_remove_collectible(void *mlx_ptr, t_list **lst, int x, int y)
{
	t_image	*tmp;
	t_list	*prev;
	t_list	*curent;

	prev = NULL;
	curent = *lst;
	while (curent != NULL)
	{
		tmp = (t_image *)curent->content;
		if (tmp->pos.x == x && tmp->pos.y == y)
		{
			ft_free_c(mlx_ptr, lst, &curent, &prev);
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}
