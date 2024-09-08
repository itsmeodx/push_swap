/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:33:03 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/25 15:08:13 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_y(t_stack *y, t_dlist *tmp)
{
	if (y->head)
	{
		tmp->next = y->head;
		tmp->prev = y->head->prev;
		y->head->prev->next = tmp;
		y->head->prev = tmp;
	}
	else
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	y->head = tmp;
	y->size++;
}

bool	push(t_stack *x, t_stack *y)
{
	t_dlist	*tmp;

	if (x->size == 0)
		return (false);
	tmp = x->head;
	x->head = x->head->next;
	x->head->prev = tmp->prev;
	x->head->prev->next = x->head;
	set_stack_y(y, tmp);
	x->size--;
	if (x->size == 0)
		x->head = NULL;
	return (true);
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
