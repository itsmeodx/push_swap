/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:03:52 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 16:08:56 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_while(t_push_swap *ps, int *arr, int *size, void (*func)(t_stack *))
{
	while (true)
	{
		if (*(int *)ps->b->head->content == arr[*size - 1])
		{
			pa(ps->a, ps->b);
			(*size)--;
			break ;
		}
		else
			func(ps->b);
	}
}

void	push_btoa(t_push_swap *ps, int *arr)
{
	int	size;

	size = ps->b->size;
	while (size > 0)
	{
		if (is_biggest_above_median(ps->b, arr, ps->b->size))
			ft_while(ps, arr, &size, rb);
		else
			ft_while(ps, arr, &size, rrb);
	}
}
