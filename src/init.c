/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 08:36:32 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 16:20:35 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init_stack(t_stack *a, int n)
{
	t_dlist	*new;
	int		*data;

	if (is_duplicate(a, n))
		return (false);
	data = malloc(sizeof(int));
	if (!data)
		return (false);
	*data = n;
	new = ft_dlstnew(data);
	if (!new)
	{
		free(data);
		return (false);
	}
	ft_dlstadd_back(&a->head, new);
	a->size++;
	return (true);
}

bool	is_duplicate(t_stack *a, int n)
{
	t_dlist	*tmp;
	int		i;

	i = -1;
	tmp = a->head;
	while (++i < a->size)
	{
		if (*(int *)tmp->content == n)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
