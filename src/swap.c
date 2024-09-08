/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:18:02 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/22 00:39:07 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_stack *x)
{
	t_dlist	*tmp;

	if (x->size < 2)
		return (false);
	tmp = x->head;
	x->head = x->head->next;
	x->head->prev = tmp->prev;
	x->head->prev->next = x->head;
	tmp->next = x->head->next;
	tmp->prev = x->head;
	x->head->next->prev = tmp;
	x->head->next = tmp;
	return (true);
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
