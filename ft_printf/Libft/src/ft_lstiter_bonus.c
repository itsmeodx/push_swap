/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:49:33 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 16:13:05 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_dlstiter(t_dlist *lst, void (*f)(void *))
{
	t_dlist	*tmp;

	if (lst && f)
	{
		tmp = lst;
		while (tmp && tmp->next != lst)
		{
			(*f)(tmp->content);
			tmp = tmp->next;
		}
		if (tmp)
			(*f)(tmp->content);
	}
}
