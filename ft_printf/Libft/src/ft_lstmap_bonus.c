/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:46:05 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 16:15:25 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;
	void	*ptr;

	first = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			ptr = f(lst->content);
			node = ft_lstnew(ptr);
			if (!node)
			{
				ft_lstclear(&first, del);
				free(ptr);
				return (NULL);
			}
			ft_lstadd_back(&first, node);
			lst = lst->next;
		}
	}
	return (first);
}

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*first;
	t_dlist	*node;
	t_dlist	*tmp;
	void	*ptr;

	first = NULL;
	if (lst && f && del)
	{
		tmp = lst;
		while (tmp && tmp->next != lst)
		{
			ptr = f(tmp->content);
			node = ft_dlstnew(ptr);
			if (!node)
			{
				ft_dlstclear(&first, del);
				free(ptr);
				return (NULL);
			}
			ft_dlstadd_back(&first, node);
			tmp = tmp->next;
		}
	}
	return (first);
}
