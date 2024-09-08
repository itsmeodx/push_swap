/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:04:08 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/26 16:29:52 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_push_swap *ps)
{
	if (ps->a->size == 2)
		sort_two(ps->a);
	else if (ps->a->size == 3)
		sort_three(ps->a);
	else if (ps->a->size == 4)
		sort_four(ps);
	else if (ps->a->size == 5)
		sort_five(ps);
}

void	sort_two(t_stack *a)
{
	if (*(int *)a->head->content > *(int *)a->head->next->content)
		sa(a);
}

void	sort_three(t_stack *a)
{
	while (!is_sorted(a))
	{
		if (*(int *)a->head->content > *(int *)a->head->next->content)
		{
			if (*(int *)a->head->content
				< *(int *)a->head->next->next->content)
				sa(a);
			else
				ra(a);
		}
		else
			rra(a);
	}
}

void	sort_four(t_push_swap *ps)
{
	int	*arr;

	arr = push_atoarr(ps);
	bubble_sort(arr, ps->a->size);
	while (*(int *)ps->a->head->content != arr[0])
	{
		if (is_smallest_above_median(ps->a, arr, ps->a->size))
			while (*(int *)ps->a->head->content != arr[0])
				ra(ps->a);
		else
			while (*(int *)ps->a->head->content != arr[0])
				rra(ps->a);
	}
	if (is_sorted(ps->a))
	{
		free(arr);
		return ;
	}
	pb(ps->a, ps->b);
	sort_three(ps->a);
	pa(ps->a, ps->b);
	free(arr);
}

void	sort_five(t_push_swap *ps)
{
	int	*arr;

	arr = push_atoarr(ps);
	bubble_sort(arr, ps->a->size);
	while (*(int *)ps->a->head->content != arr[0])
	{
		if (is_smallest_above_median(ps->a, arr, ps->a->size))
			while (*(int *)ps->a->head->content != arr[0])
				ra(ps->a);
		else
			while (*(int *)ps->a->head->content != arr[0])
				rra(ps->a);
	}
	if (is_sorted(ps->a))
	{
		free(arr);
		return ;
	}
	pb(ps->a, ps->b);
	sort_four(ps);
	pa(ps->a, ps->b);
	free(arr);
}
