/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_lst_of_enemy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:13 by ogrativ           #+#    #+#             */
/*   Updated: 2024/07/30 15:17:18 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/so_long.h"

void	ft_clear_lst_of_enemy(void *mlx_ptr, t_list **lst)
{
	t_list	*prev;

	if ((*lst) == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		prev = *lst;
		ft_free_enemy(mlx_ptr, (*lst)->content);
		*lst = (*lst)->next;
		free(prev);
	}
}
