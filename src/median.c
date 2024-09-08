/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:08:40 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/30 19:19:58 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_nearest_above_median(t_stack *a, int *arr, int min, int max)
{
	t_stack	tmp;
	int		size;
	int		i;

	i = 1;
	tmp = *a;
	size = tmp.size;
	while (i <= size)
	{
		if (is_a_in_range(&tmp, arr, min, max))
			break ;
		else if (is_a_before_range(&tmp, arr, min))
			break ;
		tmp.head = tmp.head->next;
		i++;
	}
	if ((float)i <= (float)size / 2.0
		|| (float)i - (float)0.5 == (float)size / 2.0)
		return (true);
	return (false);
}

bool	is_smallest_above_median(t_stack *a, int *arr, int size)
{
	t_dlist	*tmp;
	int		smallest;
	int		i;

	i = 1;
	tmp = a->head;
	smallest = arr[0];
	while (i < size)
	{
		if (*(int *)tmp->content == smallest)
			break ;
		tmp = tmp->next;
		i++;
	}
	if ((float)i <= (float)size / 2.0
		|| (float)i - (float)0.5 == (float)size / 2.0)
		return (true);
	return (false);
}

bool	is_biggest_above_median(t_stack *b, int *arr, int size)
{
	t_dlist	*tmp;
	int		biggest;
	int		i;

	i = 1;
	tmp = b->head;
	biggest = arr[size - 1];
	while (i < size)
	{
		if (*(int *)tmp->content == biggest)
			break ;
		tmp = tmp->next;
		i++;
	}
	if ((float)i <= (float)size / 2.0
		|| (float)i - (float)0.5 == (float)size / 2.0)
		return (true);
	return (false);
}
