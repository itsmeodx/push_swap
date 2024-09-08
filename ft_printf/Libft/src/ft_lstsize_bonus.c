/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:04:17 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 16:14:47 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*curr;

	size = 0;
	curr = lst;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int	ft_dlstsize(t_dlist *lst)
{
	int		size;
	t_dlist	*curr;

	size = 0;
	curr = lst;
	while (curr && curr->next != lst)
	{
		size++;
		curr = curr->next;
	}
	if (curr)
		size++;
	return (size);
}
