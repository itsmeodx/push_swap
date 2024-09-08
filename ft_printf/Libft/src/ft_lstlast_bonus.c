/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:17:39 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 16:00:33 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next && last_node->next != lst)
		last_node = last_node->next;
	return (last_node);
}
