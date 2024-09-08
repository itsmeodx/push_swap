/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 06:54:22 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 19:09:50 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_a_before_range(t_stack *a, int *arr, int min)
{
	int		k;
	int		value;

	k = 0;
	value = *(int *)a->head->content;
	while (k < min)
	{
		if (value == arr[k])
			return (true);
		k++;
	}
	return (false);
}

bool	is_a_in_range(t_stack *a, int *arr, int min, int max)
{
	int		value;

	value = *(int *)a->head->content;
	while (min <= max)
	{
		if (value == arr[min])
			return (true);
		min++;
	}
	return (false);
}

void	push_or_rotate(t_push_swap *ps, int *arr)
{
	while (true)
	{
		if (is_a_in_range(ps->a, arr, ps->min, ps->max))
		{
			pb(ps->a, ps->b);
			ps->min++;
			break ;
		}
		else if (is_a_before_range(ps->a, arr, ps->min))
		{
			pb(ps->a, ps->b);
			rb(ps->b);
			ps->min++;
			break ;
		}
		else
		{
			if (is_nearest_above_median(ps->a, arr, ps->min, ps->max))
				ra(ps->a);
			else
				rra(ps->a);
		}
	}
}

int	set_range(int size)
{
	if (size > 5 && size <= 16)
		return (3);
	else if (size > 15 && size <= 100)
		return (15);
	else
		return (40);
}

void	push_atob(t_push_swap *ps, int *arr)
{
	int	size;

	ps->max = set_range(ps->a->size) - 1;
	size = ps->a->size;
	while (ps->min < size)
	{
		push_or_rotate(ps, arr);
		if (ps->max + 1 < size)
			ps->max++;
	}
}
