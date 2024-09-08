/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:30:41 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/19 18:11:47 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new_lst;

	new_lst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = new_lst;
	new_lst->prev = new_lst;
	return (new_lst);
}
