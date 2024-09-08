/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:53:34 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 16:16:42 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*curr_node;

	if (lst && del)
	{
		next_node = *lst;
		while (next_node)
		{
			curr_node = next_node;
			next_node = next_node->next;
			ft_lstdelone(curr_node, del);
		}
		*lst = NULL;
	}
}

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*next_node;
	t_dlist	*curr_node;

	if (lst && del)
	{
		next_node = *lst;
		while (next_node && next_node->next != *lst)
		{
			curr_node = next_node;
			next_node = next_node->next;
			ft_dlstdelone(curr_node, del);
		}
		if (next_node)
			ft_dlstdelone(next_node, del);
		*lst = NULL;
	}
}
