/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:13:25 by oouaadic          #+#    #+#             */
/*   Updated: 2024/06/01 17:57:15 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *a)
{
	t_dlist	*tmp;

	if (!a->head)
		return (false);
	tmp = a->head;
	while (tmp->next && tmp->next != a->head)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	is_rev_sorted(t_stack *a)
{
	t_dlist	*tmp;

	tmp = a->head;
	while (tmp->next && tmp->next != a->head)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	reverse_sort(t_stack *a, t_stack *b)
{
	while (a->size - 1)
	{
		rra(a);
		pb(a, b);
	}
	while (b->size)
		pa(a, b);
}
